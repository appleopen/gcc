/* APPLE LOCAL file debugging */
/* C tree & rtl accessors defined as functions for use in a debugger.
   Copyright (C) 2001  Free Software Foundation, Inc.
   Contributed by Ira L. Ruben (ira@apple.com)

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* What we do here is to instantiate each macro as a function *BY
   THE SAME NAME*.  Depends on the macro not being expanded when
   it is surrounded by parens.  
  
   Note that this file represents the common accessors for both
   C and C++.  It is included as part of c-idebug.c and also
   as part of cp/cp-idebug.c where these files are built for
   their respective compilers and contain the language specific
   accessors for their language (i.e., c-idebug.c have the 
   accessors for c-tree.h and cp/cp-idebug.c have the accessors
   for cp-tree.h.  */

#include "config.h"

#ifdef ENABLE_IDEBUG

#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "flags.h"
#include "c-common.h"

#define fn_0(name,rt)             rt (name) (void); \
				  rt (name) (void)                { return name(); }
#define fn_1(name,rt,p1)          rt (name)(p1); \
			          rt (name) (p1 a)                { return name(a); }
#define fn_2(name,rt,p1,p2)       rt (name)(p1,p2); \
			          rt (name) (p1 a,p2 b)           { return name(a,b); }
#define fn_3(name,rt,p1,p2,p3)    rt (name)(p1,p2,p3); \
			          rt (name) (p1 a,p2 b,p3 c)      { return name(a,b,c); }
#define fn_4(name,rt,p1,p2,p3,p4) rt (name) (p1,p2,p3,p4); \
				  rt (name) (p1 a,p2 b,p3 c,p4 d) { return name(a,b,c,d); }

fn_1( RP, tree, tree )

/* Macros from tree.h  */

fn_1( TREE_CODE_CLASS, int, int )
fn_1( IS_EXPR_CODE_CLASS, char, int )
fn_1( TREE_CODE_LENGTH, int, int )
fn_1( TREE_CODE, enum tree_code, tree )
fn_1( TREE_TYPE, tree, tree )
fn_1( TREE_CHAIN, tree, tree )
fn_1( INTEGRAL_TYPE_P, int, tree )
fn_1( FLOAT_TYPE_P, int, tree )
fn_1( AGGREGATE_TYPE_P, int, tree )
fn_1( POINTER_TYPE_P, int, tree )
fn_1( BOUNDED_INDIRECT_TYPE_P, int, tree )
fn_1( BOUNDED_POINTER_TYPE_P, int, tree )
fn_1( BOUNDED_REFERENCE_TYPE_P, int, tree )
fn_1( MAYBE_BOUNDED_INDIRECT_TYPE_P, int, tree )
fn_1( MAYBE_BOUNDED_POINTER_TYPE_P, int, tree )
fn_1( MAYBE_BOUNDED_REFERENCE_TYPE_P, int, tree )
fn_1( COMPLETE_TYPE_P, int, tree )
fn_1( VOID_TYPE_P, int, tree )
fn_1( COMPLETE_OR_VOID_TYPE_P, int, tree )
fn_1( COMPLETE_OR_UNBOUND_ARRAY_TYPE_P, int, tree )
fn_1( TYPE_P, int, tree )
fn_1( TREE_ADDRESSABLE, int, tree )
fn_1( TREE_STATIC, int, tree )
fn_1( TREE_NO_UNUSED_WARNING, int, tree )
fn_1( TREE_VIA_VIRTUAL, int, tree )
fn_1( TREE_CONSTANT_OVERFLOW, int, tree )
fn_1( TREE_SYMBOL_REFERENCED, int, tree )
fn_1( TREE_OVERFLOW, int, tree )
fn_1( TREE_PUBLIC, int, tree )
fn_1( TREE_VIA_PUBLIC, int, tree )
fn_1( TREE_VIA_PRIVATE, int, tree )
fn_1( TREE_VIA_PROTECTED, int, tree )
fn_1( TREE_SIDE_EFFECTS, int, tree )
fn_1( TREE_THIS_VOLATILE, int, tree )
fn_1( TREE_READONLY, int, tree )
fn_1( TREE_READONLY_DECL_P, int, tree )
fn_1( TREE_CONSTANT, int, tree )
fn_1( TREE_UNSIGNED, int, tree )
fn_1( TYPE_TRAP_SIGNED, int, tree )
fn_1( TREE_ASM_WRITTEN, int, tree )
fn_1( TREE_USED, int, tree )
fn_1( TREE_NOTHROW, int, tree )
fn_1( TREE_PRIVATE, int, tree )
fn_1( TREE_PROTECTED, int, tree )
fn_1( TREE_BOUNDED, int, tree )
fn_1( TREE_DEPRECATED, int, tree )
/* APPLE LOCAL unavailable (Radar 2809697) --ilr */
fn_1( TREE_UNAVAILABLE, int, tree )
fn_1( TREE_LANG_FLAG_0, int, tree )
fn_1( TREE_LANG_FLAG_1, int, tree )
fn_1( TREE_LANG_FLAG_2, int, tree )
fn_1( TREE_LANG_FLAG_3, int, tree )
fn_1( TREE_LANG_FLAG_4, int, tree )
fn_1( TREE_LANG_FLAG_5, int, tree )
fn_1( TREE_LANG_FLAG_6, int, tree )
fn_1( TREE_INT_CST_LOW, unsigned HOST_WIDE_INT, tree )
fn_1( TREE_INT_CST_HIGH, HOST_WIDE_INT, tree )
fn_2( INT_CST_LT, int, tree, tree )
fn_2( INT_CST_LT_UNSIGNED, int, tree, tree )
fn_1( TREE_CST_RTL, rtx, tree )
     /* APPLE FIXME */
     /* fn_1( TREE_REAL_CST, REAL_VALUE_TYPE, tree ) */
fn_1( TREE_STRING_LENGTH, int, tree )
fn_1( TREE_STRING_POINTER, char*, tree )
fn_1( TREE_REALPART, tree, tree )
fn_1( TREE_IMAGPART, tree, tree )
fn_1( IDENTIFIER_LENGTH, int, tree )
fn_1( IDENTIFIER_POINTER, char*, tree )
fn_1( TREE_PURPOSE, tree, tree )
fn_1( TREE_VALUE, tree, tree )
fn_1( TREE_VEC_LENGTH, int, tree )
fn_2( TREE_VEC_ELT, tree, tree, int )
fn_1( SAVE_EXPR_CONTEXT, tree, tree )
fn_1( SAVE_EXPR_RTL, rtx, tree )
fn_1( SAVE_EXPR_NOPLACEHOLDER, int, tree )
fn_1( SAVE_EXPR_PERSISTENT_P, int, tree )
fn_1( RTL_EXPR_SEQUENCE, rtx, tree )
fn_1( RTL_EXPR_RTL, rtx, tree )
fn_1( CONSTRUCTOR_ELTS, tree, tree )
fn_2( TREE_OPERAND, tree, tree, int )
fn_1( TREE_COMPLEXITY, int, tree )
fn_1( LABELED_BLOCK_LABEL, tree, tree )
fn_1( LABELED_BLOCK_BODY, tree, tree )
fn_1( EXIT_BLOCK_LABELED_BLOCK, tree, tree )
fn_1( EXIT_BLOCK_RETURN, tree, tree )
fn_1( LOOP_EXPR_BODY, tree, tree )
fn_1( EXPR_WFL_NODE, tree, tree )
fn_1( EXPR_WFL_FILENAME, char*, tree )
fn_1( EXPR_WFL_FILENAME_NODE, tree, tree )
fn_1( EXPR_WFL_LINENO, int, tree )
fn_1( EXPR_WFL_COLNO, int, tree )
fn_1( EXPR_WFL_LINECOL, int, tree )
fn_3( EXPR_WFL_SET_LINECOL, int, tree, int, int )
fn_1( EXPR_WFL_EMIT_LINE_NOTE, int, tree )
fn_1( BLOCK_VARS, tree, tree )
fn_1( BLOCK_SUBBLOCKS, tree, tree )
fn_1( BLOCK_SUPERCONTEXT, tree, tree )
fn_1( BLOCK_CHAIN, tree, tree )
fn_1( BLOCK_ABSTRACT_ORIGIN, tree, tree )
fn_1( BLOCK_ABSTRACT, int, tree )
fn_1( BLOCK_HANDLER_BLOCK, int, tree )
fn_1( BLOCK_NUMBER, int, tree )
fn_1( TYPE_UID, int, tree )
fn_1( TYPE_SIZE, tree, tree )
fn_1( TYPE_SIZE_UNIT, tree, tree )
fn_1( TYPE_MODE, int, tree )
fn_1( TYPE_VALUES, tree, tree )
fn_1( TYPE_DOMAIN, tree, tree )
fn_1( TYPE_FIELDS, tree, tree )
fn_1( TYPE_METHODS, tree, tree )
fn_1( TYPE_VFIELD, tree, tree )
fn_1( TYPE_ARG_TYPES, tree, tree )
fn_1( TYPE_METHOD_BASETYPE, tree, tree )
fn_1( TYPE_OFFSET_BASETYPE, tree, tree )
fn_1( TYPE_POINTER_TO, tree, tree )
fn_1( TYPE_REFERENCE_TO, tree, tree )
fn_1( TYPE_MIN_VALUE, tree, tree )
fn_1( TYPE_MAX_VALUE, tree, tree )
fn_1( TYPE_PRECISION, int, tree )
fn_1( TYPE_SYMTAB_ADDRESS, int, tree )
fn_1( TYPE_SYMTAB_POINTER, char*, tree )
fn_1( TYPE_NAME, tree, tree )
fn_1( TYPE_NEXT_VARIANT, tree, tree )
fn_1( TYPE_MAIN_VARIANT, tree, tree )
fn_1( TYPE_CONTEXT, tree, tree )
fn_1( TYPE_LANG_SPECIFIC, struct lang_type*, tree )
fn_1( TYPE_DEBUG_REPRESENTATION_TYPE, tree, tree )
fn_2( TYPE_MAIN_VARIANTS_PHYSICALLY_EQUAL_P, int, tree, tree )
fn_1( TYPE_MAIN_PHYSICAL_VARIANT, tree, tree )
fn_1( TYPE_BINFO, tree, tree )
fn_1( TYPE_ALIAS_SET, int, tree )
fn_1( TYPE_ALIAS_SET_KNOWN_P, int, tree )
fn_1( TYPE_ATTRIBUTES, tree, tree )
fn_1( TYPE_ALIGN, int, tree )
fn_1( TYPE_USER_ALIGN, int, tree )
fn_1( TYPE_ALIGN_UNIT, int, tree )
fn_1( TYPE_STUB_DECL, tree, tree )
fn_1( TYPE_NO_FORCE_BLK, int, tree )
fn_1( TYPE_IS_SIZETYPE, int, tree )
fn_1( TYPE_RETURNS_STACK_DEPRESSED, int, tree )
fn_1( TYPE_VOLATILE, int, tree )
fn_1( TYPE_READONLY, int, tree )
fn_1( TYPE_RESTRICT, int, tree )
fn_1( TYPE_BOUNDED, int, tree )
fn_1( TYPE_QUALS, int, tree )
fn_1( TREE_EXPR_QUALS, int, tree )
fn_1( TREE_FUNC_QUALS, int, tree )
fn_1( TYPE_LANG_FLAG_0, int, tree )
fn_1( TYPE_LANG_FLAG_1, int, tree )
fn_1( TYPE_LANG_FLAG_2, int, tree )
fn_1( TYPE_LANG_FLAG_3, int, tree )
fn_1( TYPE_LANG_FLAG_4, int, tree )
fn_1( TYPE_LANG_FLAG_5, int, tree )
fn_1( TYPE_LANG_FLAG_6, int, tree )
fn_1( TYPE_STRING_FLAG, int, tree )
fn_1( TYPE_ARRAY_MAX_SIZE, tree, tree )
fn_1( TYPE_VECTOR_SUBPARTS, int, tree )
fn_1( TYPE_NEEDS_CONSTRUCTING, int, tree )
fn_1( TYPE_TRANSPARENT_UNION, int, tree )
fn_1( TYPE_NONALIASED_COMPONENT, int, tree )
fn_1( TYPE_PACKED, int, tree )
fn_1( TYPE_BOUNDED_VALUE, tree, tree )
fn_1( TYPE_BOUNDED_BASE, tree, tree )
fn_1( TYPE_BOUNDED_EXTENT, tree, tree )
fn_1( TYPE_BOUNDED_SUBTYPE, tree, tree )
fn_1( TYPE_UNBOUNDED_VARIANT, tree, tree )
fn_1( TYPE_POINTER_DEPTH, int, tree )
fn_1( TYPE_AMBIENT_BOUNDEDNESS, int, tree )
fn_1( BINFO_TYPE, tree, tree )
fn_1( BINFO_OFFSET, tree, tree )
fn_1( TYPE_BINFO_OFFSET, tree, tree )
fn_1( BINFO_OFFSET_ZEROP, int, tree )
fn_1( BINFO_VTABLE, tree, tree )
fn_1( TYPE_BINFO_VTABLE, tree, tree )
fn_1( BINFO_VIRTUALS, tree, tree )
fn_1( TYPE_BINFO_VIRTUALS, tree, tree )
fn_1( BINFO_BASETYPES, tree, tree )
fn_1( TYPE_BINFO_BASETYPES, tree, tree )
fn_1( BINFO_N_BASETYPES, int, tree )
fn_2( BINFO_BASETYPE, tree, tree, int )
fn_2( TYPE_BINFO_BASETYPE, tree, tree, int )
fn_1( BINFO_VPTR_FIELD, tree, tree )
fn_1( BINFO_SIZE, tree, tree )
fn_1( BINFO_SIZE_UNIT, tree, tree )
fn_1( TYPE_BINFO_SIZE, tree, tree )
fn_1( TYPE_BINFO_SIZE_UNIT, tree, tree )
fn_1( BINFO_INHERITANCE_CHAIN, tree, tree )
fn_1( DECL_P, int, tree )
fn_1( DECL_NAME, tree, tree )
fn_1( DECL_ASSEMBLER_NAME, tree, tree )
fn_1( DECL_ASSEMBLER_NAME_SET_P, int, tree )
fn_1( DECL_SECTION_NAME, tree, tree )
fn_1( DECL_CONTEXT, tree, tree )
fn_1( DECL_FIELD_CONTEXT, tree, tree )
fn_1( DECL_ATTRIBUTES, tree, tree )
fn_1( DECL_FIELD_OFFSET, tree, tree )
fn_1( DECL_FIELD_BIT_OFFSET, tree, tree )
fn_1( DECL_BIT_FIELD_TYPE, tree, tree )
fn_1( DECL_ARGUMENTS, tree, tree )
fn_1( DECL_RESULT_FLD, tree, tree )
fn_1( DECL_RESULT, tree, tree )
fn_1( DECL_ORIGINAL_TYPE, tree, tree )
fn_1( DECL_ARG_TYPE_AS_WRITTEN, tree, tree )
fn_1( DECL_INITIAL, tree, tree )
fn_1( DECL_ARG_TYPE, tree, tree )
fn_1( DECL_QUALIFIER, tree, tree )
fn_1( DECL_SOURCE_FILE, char*, tree )
fn_1( DECL_SOURCE_LINE, int, tree )
fn_1( DECL_SIZE, tree, tree )
fn_1( DECL_SIZE_UNIT, tree, tree )
fn_1( DECL_ALIGN, int, tree )
fn_1( DECL_ALIGN_UNIT, int, tree )
fn_1( DECL_OFFSET_ALIGN, int, tree )
fn_1( DECL_USER_ALIGN, int, tree )
fn_1( DECL_MODE, int, tree )
fn_1( DECL_RTL, rtx, tree )
fn_1( DECL_RTL_SET_P, int, tree )
fn_2( COPY_DECL_RTL, rtx, tree, tree )
fn_1( DECL_RTL_IF_SET, rtx, tree )
fn_1( DECL_LIVE_RANGE_RTL, rtx, tree )
fn_1( DECL_INCOMING_RTL, rtx, tree )
fn_1( DECL_SAVED_INSNS, struct function *, tree )
fn_1( DECL_FUNCTION_CODE, enum built_in_function, tree )
fn_1( DECL_VINDEX, tree, tree )
fn_1( DECL_FCONTEXT, tree, tree )
fn_1( DECL_UID, int, tree )
fn_1( DECL_ABSTRACT_ORIGIN, tree, tree )
fn_1( DECL_ORIGIN, tree,tree )
fn_1( DECL_FROM_INLINE, int, tree )
fn_1( DECL_IGNORED_P, int, tree )
fn_1( DECL_ABSTRACT, int, tree )
fn_1( DECL_IN_SYSTEM_HEADER, int, tree )
fn_1( DECL_COMMON, int, tree )
fn_1( DECL_COALESCED, int, tree )
fn_1( DECL_LANG_SPECIFIC, struct lang_decl *, tree )
fn_1( DECL_EXTERNAL, int, tree )
fn_1( TYPE_DECL_SUPPRESS_DEBUG, int, tree )
fn_1( DECL_REGISTER, int, tree )
fn_1( DECL_ERROR_ISSUED, int, tree )
fn_1( DECL_PACKED, int, tree )
fn_1( DECL_NO_STATIC_CHAIN, int, tree )
fn_1( DECL_NONLOCAL, int, tree )
fn_1( DECL_INLINE, int, tree )
fn_1( DECL_UNINLINABLE, int, tree )
fn_1( DECL_BUILT_IN_NONANSI, int, tree )
fn_1( DECL_IS_MALLOC, int, tree )
fn_1( DECL_IS_PURE, int, tree )
fn_1( DECL_BIT_FIELD, int, tree )
fn_1( DECL_TOO_LATE, int, tree )
fn_1( DECL_IN_TEXT_SECTION, int, tree )
fn_1( DECL_BUILT_IN, int, tree )
fn_1( DECL_BUILT_IN_CLASS, int, tree )
fn_1( DECL_VIRTUAL_P, int, tree )
fn_1( DECL_DEFER_OUTPUT, int, tree )
fn_1( DECL_TRANSPARENT_UNION, int, tree )
fn_1( DECL_STATIC_CONSTRUCTOR, int, tree )
fn_1( DECL_STATIC_DESTRUCTOR, int, tree )
fn_1( DECL_ARTIFICIAL, int, tree )
fn_1( DECL_WEAK, int, tree )
/* APPLE LOCAL weak_import (Radar 2809704) --ilr */
fn_1( DECL_WEAK_IMPORT, int, tree )
fn_1( DECL_ONE_ONLY, int, tree )
fn_1( DECL_COMDAT, int, tree )
fn_1( DECL_NO_INSTRUMENT_FUNCTION_ENTRY_EXIT, int, tree )
fn_1( DECL_NO_CHECK_MEMORY_USAGE, int, tree )
fn_1( DECL_NO_LIMIT_STACK, int, tree )
fn_1( DECL_LANG_FLAG_0, int, tree )
fn_1( DECL_LANG_FLAG_1, int, tree )
fn_1( DECL_LANG_FLAG_2, int, tree )
fn_1( DECL_LANG_FLAG_3, int, tree )
fn_1( DECL_LANG_FLAG_4, int, tree )
fn_1( DECL_LANG_FLAG_5, int, tree )
fn_1( DECL_LANG_FLAG_6, int, tree )
fn_1( DECL_LANG_FLAG_7, int, tree )
fn_1( DECL_NON_ADDR_CONST_P, int, tree )
fn_1( DECL_NONADDRESSABLE_P, int, tree )
fn_1( DECL_POINTER_ALIAS_SET, int, tree )
fn_1( DECL_POINTER_ALIAS_SET_KNOWN_P, int, tree )
fn_1( DECL_POINTER_DEPTH, int, tree )
fn_1( MAIN_NAME_P, int, tree )

/* Macros from rtl.h  */

fn_1( GET_RTX_LENGTH, int, rtx )
fn_1( GET_RTX_NAME, char*, rtx )
fn_1( GET_RTX_FORMAT, char*, rtx )
fn_1( GET_RTX_CLASS, char, rtx )
fn_1( GET_CODE, int, rtx )
fn_1( GET_MODE, int, rtx )
fn_1( RTX_INTEGRATED_P, int, rtx )
fn_1( RTX_UNCHANGING_P, int, rtx )
fn_1( RTX_FRAME_RELATED_P, int, rtx )
fn_1( GET_NUM_ELEM, int, rtvec )
fn_1( REG_P, int, rtx )
fn_1( LABEL_P, int, rtx )
fn_1( JUMP_P, int, rtx )
fn_1( NOTE_P, int, rtx )
fn_1( BARRIER_P, int, rtx )
fn_1( JUMP_TABLE_DATA_P, int, rtx )
fn_1( CONSTANT_P, int, rtx )
fn_2( RTVEC_ELT, rtx, rtvec, int )
fn_2( XWINT, HOST_WIDE_INT, rtx, int )
fn_2( XINT, int, rtx, int )
fn_2( XSTR, char*, rtx, int )
fn_2( XEXP, rtx, rtx, int )
fn_2( XVEC, rtvec, rtx, int )
fn_2( XMODE, enum machine_mode, rtx, int )
fn_2( XBITMAP, struct bitmap_head_def *, rtx, int )
fn_2( XTREE, tree, rtx, int )
fn_2( XBBDEF, struct basic_block_def *, rtx, int )
fn_3( XVECEXP, rtx, rtx, int, int )
fn_2( XVECLEN, int, rtx, int )
fn_2( X0WINT, HOST_WIDE_INT, rtx, int )
fn_2( X0INT, int, rtx, int )
fn_2( X0UINT, unsigned int, rtx, int )
fn_2( X0STR, char *, rtx, int )
fn_2( X0EXP, rtx, rtx, int )
fn_2( X0VEC, rtvec, rtx, int )
fn_2( X0MODE, enum machine_mode, rtx, int )
fn_2( X0BITMAP, struct bitmap_head_def *, rtx, int )
fn_2( X0TREE, tree, rtx, int )
fn_2( X0BBDEF, struct basic_block_def *, rtx, int )
fn_2( X0ADVFLAGS, addr_diff_vec_flags, rtx, int )
fn_2( X0CSELIB, struct cselib_val_struct *, rtx, int )
fn_2( X0MEMATTR, mem_attrs *, rtx, int)
fn_3( XCWINT, HOST_WIDE_INT, rtx, int, int )
fn_3( XCINT, int, rtx, int, int )
fn_3( XCUINT, unsigned int, rtx, int, int )
fn_3( XCSTR, char *, rtx, int, int )
fn_3( XCEXP, rtx, rtx, int, int )
fn_3( XCVEC, rtvec, rtx, int, int )
fn_3( XCMODE, enum machine_mode, rtx, int, int )
fn_3( XCBITMAP, struct bitmap_head_def *, rtx, int, int )
fn_3( XCTREE, tree, rtx, int, int )
fn_3( XCBBDEF, struct basic_block_def *, rtx, int, int )
fn_3( XCADVFLAGS, addr_diff_vec_flags, rtx, int, int )
fn_3( XCCSELIB, struct cselib_val_struct *, rtx, int, int )
fn_4( XCVECEXP, rtx, rtx, int, int, int )
fn_3( XCVECLEN, int, rtx, int, int )
fn_4( XC2EXP, rtx, rtx, int, int, int )
fn_1( INSN_P, int, rtx )
fn_1( INSN_UID, int, rtx )
fn_1( PREV_INSN, rtx, rtx )
fn_1( NEXT_INSN, rtx, rtx )
fn_1( PATTERN, rtx, rtx )
fn_1( INSN_CODE, int, rtx )
fn_1( LOG_LINKS, rtx, rtx )
fn_1( INSN_DELETED_P, int, rtx )
fn_1( CONST_CALL_P, int, rtx )
fn_1( SIBLING_CALL_P, int, rtx )
fn_1( INSN_ANNULLED_BRANCH_P, int, rtx )
fn_1( INSN_DEAD_CODE_P, int, rtx )
fn_1( INSN_FROM_TARGET_P, int, rtx )
fn_1( ADDR_DIFF_VEC_FLAGS, addr_diff_vec_flags, rtx )
fn_1( CSELIB_VAL_PTR, struct cselib_val_struct *, rtx )
fn_1( REG_NOTES, rtx, rtx )
fn_1( REG_NOTE_KIND, enum reg_note, rtx )
fn_1( GET_REG_NOTE_NAME, char *, rtx )
fn_1( CALL_INSN_FUNCTION_USAGE, rtx, rtx )
fn_1( CODE_LABEL_NUMBER, int, rtx )
fn_1( NOTE_SOURCE_FILE, char *, rtx )
fn_1( NOTE_BLOCK, tree, rtx )
fn_1( NOTE_EH_HANDLER, int, rtx )
fn_1( NOTE_RANGE_INFO, rtx, rtx )
fn_1( NOTE_LIVE_INFO, rtx, rtx )
fn_1( NOTE_BASIC_BLOCK, struct basic_block_def *, rtx )
fn_1( NOTE_EXPECTED_VALUE, rtx, rtx )
fn_1( NOTE_LINE_NUMBER, int, rtx )
fn_1( NOTE_INSN_BASIC_BLOCK_P, int, rtx )
fn_1( GET_NOTE_INSN_NAME, char*, int )
fn_1( LABEL_NAME, char*, rtx )
fn_1( LABEL_NUSES, int, rtx )
fn_1( LABEL_ALTERNATE_NAME, char *, rtx )
fn_1( ADDRESSOF_REGNO, int, rtx )
fn_1( ADDRESSOF_DECL, tree, rtx )
fn_1( JUMP_LABEL, rtx, rtx )
fn_1( LABEL_REFS, rtx, rtx )
fn_1( LABEL_NEXTREF, rtx, rtx )
fn_1( CONTAINING_INSN, rtx, rtx )
fn_1( REGNO, int, rtx )
fn_1( ORIGINAL_REGNO, unsigned int, rtx )
fn_1( REG_FUNCTION_VALUE_P, int, rtx )
fn_1( REG_USERVAR_P, int, rtx )
fn_1( REG_POINTER, int, rtx )
fn_1( HARD_REGISTER_P, int, rtx )
fn_1( HARD_REGISTER_NUM_P, int, int )
fn_1( INTVAL, HOST_WIDE_INT, rtx )
fn_1( CONST_DOUBLE_LOW, HOST_WIDE_INT, rtx )
fn_1( CONST_DOUBLE_HIGH, HOST_WIDE_INT, rtx )
fn_1( CONST_DOUBLE_CHAIN, rtx, rtx )
fn_1( CONST_DOUBLE_MEM, rtx, rtx )
fn_1( SUBREG_REG, rtx, rtx )
fn_1( SUBREG_BYTE, unsigned int, rtx )
fn_1( SUBREG_PROMOTED_VAR_P, int, rtx )
fn_1( SUBREG_PROMOTED_UNSIGNED_P, int, rtx )
fn_1( ASM_OPERANDS_TEMPLATE, char *, rtx )
fn_1( ASM_OPERANDS_OUTPUT_CONSTRAINT, char *, rtx )
fn_1( ASM_OPERANDS_OUTPUT_IDX, int, rtx )
fn_1( ASM_OPERANDS_INPUT_VEC, rtvec, rtx )
fn_1( ASM_OPERANDS_INPUT_CONSTRAINT_VEC, rtvec, rtx )
fn_2( ASM_OPERANDS_INPUT, rtx, rtx, int )
fn_1( ASM_OPERANDS_INPUT_LENGTH, int, rtx )
fn_2( ASM_OPERANDS_INPUT_CONSTRAINT_EXP, rtx, rtx, int )
fn_2( ASM_OPERANDS_INPUT_CONSTRAINT, char*, rtx, int )
fn_2( ASM_OPERANDS_INPUT_MODE, int, rtx, int )
fn_1( ASM_OPERANDS_SOURCE_FILE, char *, rtx )
fn_1( ASM_OPERANDS_SOURCE_LINE, int, rtx )
fn_1( MEM_VOLATILE_P, int, rtx )
fn_1( MEM_IN_STRUCT_P, int, rtx )
fn_1( MEM_SCALAR_P, int, rtx )
fn_1( MEM_ATTRS, mem_attrs *, rtx)
fn_1( MEM_ALIAS_SET, int, rtx )
fn_1( MEM_DECL, tree, rtx)
fn_1( MEM_OFFSET, rtx, rtx)
fn_1( MEM_SIZE, rtx, rtx)
fn_1( MEM_ALIGN, unsigned int, rtx)
fn_2( MEM_COPY_ATTRIBUTES, int, rtx, rtx )
fn_1( LABEL_OUTSIDE_LOOP_P, int, rtx )
fn_1( LABEL_REF_NONLOCAL_P, int, rtx )
fn_1( LABEL_PRESERVE_P, int, rtx )
fn_1( REG_LOOP_TEST_P, int, rtx )
fn_1( SCHED_GROUP_P, int, rtx )
fn_1( LINK_COST_ZERO, int, rtx )
fn_1( LINK_COST_FREE, int, rtx )
fn_1( SET_DEST, rtx, rtx )
fn_1( SET_SRC, rtx, rtx )
fn_1( TRAP_CONDITION, rtx, rtx )
fn_1( TRAP_CODE, rtx, rtx )
fn_1( COND_EXEC_TEST, rtx, rtx )
fn_1( COND_EXEC_CODE, rtx, rtx )
fn_1( CONSTANT_POOL_ADDRESS_P, int, rtx )
fn_1( STRING_POOL_ADDRESS_P, int, rtx )
fn_1( SYMBOL_REF_FLAG, int, rtx )
fn_1( SYMBOL_REF_USED, int, rtx )
fn_2( FIND_REG_INC_NOTE, rtx, rtx, rtx )
fn_1( RANGE_INFO_NOTE_START, rtx, rtx )
fn_1( RANGE_INFO_NOTE_END, rtx, rtx )
fn_1( RANGE_INFO_REGS, rtvec, rtx )
fn_2( RANGE_INFO_REGS_REG, rtx, rtx, int )
fn_1( RANGE_INFO_NUM_REGS, int, rtx )
fn_1( RANGE_INFO_NCALLS, int, rtx )
fn_1( RANGE_INFO_NINSNS, int, rtx )
fn_1( RANGE_INFO_UNIQUE, int, rtx )
fn_1( RANGE_INFO_BB_START, int, rtx )
fn_1( RANGE_INFO_BB_END, int, rtx )
fn_1( RANGE_INFO_LOOP_DEPTH, int, rtx )
fn_1( RANGE_INFO_LIVE_START, struct bitmap_head_def *, rtx )
fn_1( RANGE_INFO_LIVE_END, struct bitmap_head_def *, rtx )
fn_1( RANGE_INFO_MARKER_START, int, rtx )
fn_1( RANGE_INFO_MARKER_END, int, rtx )
fn_2( RANGE_REG_PSEUDO, int, rtx, int )
fn_2( RANGE_REG_COPY, int, rtx, int )
fn_2( RANGE_REG_REFS, int, rtx, int )
fn_2( RANGE_REG_SETS, int, rtx, int )
fn_2( RANGE_REG_DEATHS, int, rtx, int )
fn_2( RANGE_REG_COPY_FLAGS, int, rtx, int )
fn_2( RANGE_REG_LIVE_LENGTH, int, rtx, int )
fn_2( RANGE_REG_N_CALLS, int, rtx, int )
fn_2( RANGE_REG_SYMBOL_NODE, tree, rtx, int )
fn_2( RANGE_REG_BLOCK_NODE, tree, rtx, int )
fn_1( RANGE_VAR_LIST, rtx, rtx )
fn_1( RANGE_VAR_BLOCK, tree, rtx )
fn_1( RANGE_VAR_NUM, int, rtx )
fn_1( RANGE_LIVE_BITMAP, struct bitmap_head_def *, rtx )
fn_1( RANGE_LIVE_ORIG_BLOCK, int, rtx )
fn_1( PHI_NODE_P, int, rtx )
fn_1( CONST0_RTX, rtx, rtx )
fn_1( CONST1_RTX, rtx, rtx )
fn_1( CONST2_RTX, rtx, rtx )
fn_1( GEN_INT, rtx, int )
fn_1( COSTS_N_INSNS, int, int )

/* Macros from c-common.h  */

fn_1( DECL_SAVED_TREE, tree, tree)
fn_1( DECL_INLINED_FNS, tree, tree )
fn_1( DECL_NUM_STMTS, HOST_WIDE_INT, tree)
fn_1( C_TYPE_OBJECT_P, int, tree)
fn_1( C_TYPE_INCOMPLETE_P, int, tree)
fn_1( C_TYPE_FUNCTION_P, int, tree)
fn_1( C_TYPE_QUALS, int, tree)
fn_1( C_TYPE_OBJECT_OR_INCOMPLETE_P, int, tree)
fn_1( C_EXP_ORIGINAL_CODE, enum tree_code, tree)
fn_1( C_PROMOTING_INTEGER_TYPE_P, int, tree)
fn_1( STMT_IS_FULL_EXPR_P, int, tree)
fn_1( IF_COND, tree, tree)
fn_1( THEN_CLAUSE, tree, tree)
fn_1( ELSE_CLAUSE, tree, tree)
fn_1( WHILE_COND, tree, tree)
fn_1( WHILE_BODY, tree, tree)
fn_1( DO_COND, tree, tree)
fn_1( DO_BODY, tree, tree)
/*fn_1( RETURN_EXPR, tree, tree)*/
fn_1( EXPR_STMT_EXPR, tree, tree)
fn_1( FOR_INIT_STMT, tree, tree)
fn_1( FOR_COND, tree, tree)
fn_1( FOR_EXPR, tree, tree)
fn_1( FOR_BODY, tree, tree)
fn_1( SWITCH_COND, tree, tree)
fn_1( SWITCH_BODY, tree, tree)
fn_1( CASE_LOW, tree, tree)
fn_1( CASE_HIGH, tree, tree)
fn_1( CASE_LABEL_DECL, tree, tree)
fn_1( GOTO_DESTINATION, tree, tree)
fn_1( COMPOUND_BODY, tree, tree)
fn_1( ASM_CV_QUAL, tree, tree)
fn_1( ASM_STRING, tree, tree)
fn_1( ASM_OUTPUTS, tree, tree)
fn_1( ASM_INPUTS, tree, tree)
fn_1( ASM_CLOBBERS, tree, tree)
fn_1( DECL_STMT_DECL, tree, tree)
fn_1( STMT_EXPR_STMT, tree, tree)
fn_1( LABEL_STMT_LABEL, tree, tree)
fn_1( SCOPE_BEGIN_P, int, tree)
fn_1( SCOPE_END_P, int, tree)
fn_1( SCOPE_STMT_BLOCK, tree, tree)
fn_1( SCOPE_NULLIFIED_P, int, tree)
fn_1( SCOPE_NO_CLEANUPS_P, int, tree)
fn_1( SCOPE_PARTIAL_P, int, tree)
fn_1( ASM_VOLATILE_P, int, tree)
fn_1( STMT_LINENO, int, tree)
fn_1( STMT_LINENO_FOR_FN_P, int, tree)
fn_1( NEW_FOR_SCOPE_P, int, tree)
fn_1( ASM_INPUT_P, int, tree)
fn_1( DECL_ANON_UNION_ELEMS, tree, tree)
fn_1( DECL_C_BIT_FIELD, int, tree)
fn_1( SET_DECL_C_BIT_FIELD, int, tree)
fn_1( CLEAR_DECL_C_BIT_FIELD, int, tree)
fn_1( DECL_C_HARD_REGISTER, int, tree)
fn_1( COMPOUND_STMT_NO_SCOPE, int, tree)
fn_1( OBJC_IS_AT_KEYWORD, int, enum rid);
fn_1( OBJC_IS_PQ_KEYWORD, int, enum rid);
/* APPLE LOCAL begin AltiVec */
fn_1( ALTIVEC_IS_CONTEXT_KEYWORD, int, enum rid);
fn_1( ALTIVEC_IS_QUALIFIER, int, enum rid);
/* APPLE LOCAL end AltiVec */

tree is__test_point PARAMS ((tree));

/* The following is intended to be called only by a debugger or
   debugging code.  The function will always return 0 if the input
   node is not a decl node for the identifier "__test_point".  In that
   case it returns the node for a constant "1".
   
   You can use the identifer "__test_point" any place in a test proram
   where a constant int 1 is allowed.  By using the debugger or
   debugging code to call this routine to conditionally stop or do
   something when "__test_point" is seen makes it easier to up skip to
   the point in question if that point is heavly used for stuff you are
   not interested in.
   
   The function returns 0 if the node is not an IDENTIFIER_NODE for
   "__test_point" or not a decl node  for "__test_point".  If it is
   a integer_one_node is returned.  
   
   Note, currently it is up to the caller to determine what to do with
   the returned integer_one_node or 0.  */ 
   
tree __test_point (node)
     tree node;
{
  if (!node)
    return 0;
    
  if (TREE_CODE (node) != IDENTIFIER_NODE
      || strcmp (IDENTIFIER_POINTER (node), "__test_point") != 0)
    {
      if (TREE_CODE_CLASS (TREE_CODE (node)) != 'd'
          || !DECL_NAME (node)
	  || !IDENTIFIER_POINTER (DECL_NAME (node))
          || strcmp (IDENTIFIER_POINTER (DECL_NAME (node)), "__test_point") != 0)
	return 0;
    }
  
  return integer_one_node;
}

#endif /* ENABLE_IDEBUG */
