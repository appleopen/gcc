#  Copyright (C) 2003,2004 Free Software Foundation, Inc.
#  Contributed by Kelley Cook, June 2004.
#  Original code from Neil Booth, May 2003.
#
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2, or (at your option) any
# later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

# This Awk script reads in the option records generated from 
# opt-gather.awk, combines the flags of duplicate options and generates a
# C header file.
#
# This program uses functions from opt-functions.awk
# Usage: awk -f opt-functions.awk -f opth-gen.awk < inputfile > options.h

BEGIN {
	n_opts = 0
	n_langs = 0
        quote = "\042"
	comma = ","
	FS=SUBSEP
}

# Collect the text and flags of each option into an array
	{
		if ($1 == "Language") {
			langs[n_langs] = $2
			n_langs++;
		}
		else {
			opts[n_opts]  = $1
			flags[n_opts] = $2
			help[n_opts]  = $3
			n_opts++;
		}
	}

# Dump out an enumeration into a .h file.
# Combine the flags of duplicate options.
END {
# APPLE LOCAL optimization pragmas 3124235/3420242
print "/* This file is auto-generated by opth-gen.awk.  */"
print ""
print "#ifndef OPTIONS_H"
print "#define OPTIONS_H"
print ""

for (i = 0; i < n_opts; i++) {
	name = var_name(flags[i]);
	if (name == "")
		continue;

	print "/* Set by -" opts[i] "."
	print "   " help[i] "  */"
# APPLE LOCAL begin optimization pragmas 3124235/3420242
	if (!flag_set_p("PerFunc", flags[i])) {
	    print "extern int " name ";"
	} else {
	    if (flag_set_p("VarExists"))
		continue;
	    print "#define " name " (cl_pf_opts.fld_" name ")"
	}
	print ""
    }

print "/* Nonzero means do optimizations.  -O."
print "   Particular numeric values stand for particular amounts of optimization;"
print "   thus, -O2 stores 2 here.  However, the optimizations beyond the basic"
print "   ones are not controlled directly by this variable.  Instead, they are"
print "   controlled by individual `flag_...' variables that are defaulted"
print "   based on this variable.  */"

print "#define optimize (cl_pf_opts.fld_optimize)"

print ""
print "/* Nonzero means optimize for size.  -Os."
print "   The only valid values are zero and nonzero. When optimize_size is"
print "   nonzero, optimize defaults to 2, but certain individual code"
print "   bloating optimizations are disabled.  */"

print "#define optimize_size (cl_pf_opts.fld_optimize_size)"
print ""

print "/* Flags which may be changed per function.  */"
count = 0
print "struct cl_perfunc_opts {"

for (i = 0; i < n_opts; i++) {
	name = var_name(flags[i]);
	if (name == "")
	    continue;
	if (flag_set_p("VarExists", flags[i]))
	    continue;
	if (!flag_set_p("PerFunc", flags[i]))
	    continue;
	if (!flag_set_p("VarUint", flags[i]))
	  {
	    print "  unsigned int fld_" name ":1;"
	    count++
	  }
}

print "  unsigned int fld_optimize_size:1;"
count++

# Explicit padding so there are no holes, which might be
# handled strangely by the hashing and comparison functions.
# FIXME:  A full word of padding is used in the case where we're
# already at a word boundary; this is currently irrelevant.

print "  unsigned int padding: (HOST_BITS_PER_INT-("count"-(" count "/HOST_BITS_PER_INT)*HOST_BITS_PER_INT));"

for (i = 0; i < n_opts; i++) {
	name = var_name(flags[i]);
	if (name == "")
	    continue;
	if (flag_set_p("VarExists", flags[i]))
	    continue;
	if (!flag_set_p("PerFunc", flags[i]))
	    continue;
	if (flag_set_p("VarUint", flags[i]))
	    print "  int fld_" name ";"
}

print "  int fld_optimize;"
print "};"
print ""
print "/* cl_pf_opts changes dynamically as pragmas are handled.  */"
print "extern struct cl_perfunc_opts cl_pf_opts;"
print "/* " quote "raw" quote " options are before command line parsing. */"
print "extern struct cl_perfunc_opts cl_pf_opts_raw;"
print "/* " quote "cooked" quote " options are after command line parsing. */"
print "extern struct cl_perfunc_opts cl_pf_opts_cooked;"

for (i = 0; i < n_opts; i++) {
	name = var_name(flags[i]);
	if (name == "")
	    continue;
	if (flag_set_p("VarExists", flags[i]))
	    continue;
	if (!flag_set_p("PerFunc", flags[i]))
	    continue;
	if (!flag_set_p("VarUint", flags[i]))
	    print "extern int cl_opt_access_func_" name " (int, unsigned int);"
}

print "extern int cl_opt_access_func_optimize_size (int, unsigned int);"
# APPLE LOCAL end optimization pragmas 3124235/3420242

for (i = 0; i < n_langs; i++) {
	macros[i] = "CL_" langs[i]
	gsub( "[^A-Za-z0-9_]", "X", macros[i] )
	s = substr("            ", length (macros[i]))
	print "#define " macros[i] s " (1 << " i ")"
    }

print ""
print "enum opt_code"
print "{"
	
for (i = 0; i < n_opts; i++)
	back_chain[i] = "N_OPTS";

	for (i = 0; i < n_opts; i++) {
		# Combine the flags of identical switches.  Switches
		# appear many times if they are handled by many front
		# ends, for example.
		while( i + 1 != n_opts && opts[i] == opts[i + 1] ) {
			flags[i + 1] = flags[i] " " flags[i + 1];
			i++;
		}

	len = length (opts[i]);
	enum = "OPT_" opts[i]
	if (opts[i] == "finline-limit=")
		enum = enum "eq"
	gsub ("[^A-Za-z0-9]", "_", enum)

	# If this switch takes joined arguments, back-chain all
	# subsequent switches to it for which it is a prefix.  If
	# a later switch S is a longer prefix of a switch T, T
	# will be back-chained to S in a later iteration of this
	# for() loop, which is what we want.
	if (flags[i] ~ "Joined") {
		for (j = i + 1; j < n_opts; j++) {
			if (substr (opts[j], 1, len) != opts[i])
				break;
			back_chain[j] = enum;
		}
	}

	s = substr("                                     ", length (opts[i]))
	if (i + 1 == n_opts)
		comma = ""

	if (help[i] == "")
		hlp = "0"
	else
		hlp = "N_(\"" help[i] "\")";

	print "  " enum "," s "/* -" opts[i] " */"
}

print "  N_OPTS"
print "};"
print ""
print "#endif /* OPTIONS_H */"
}