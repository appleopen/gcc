/* Test the tester; previously part of gcc.misc-tests/dg-9.c.  */
/* { dg-prms-id 42 } */
/* { dg-options "-Wall" } */

int main (int argc, char *argv[])
{
  +;
              /* { dg-error "syntax error" "error test" { xfail *-*-* } 7 } */
  return 0;
}
/* { dg-excess-errors "expect failure" { xfail *-*-* } } */
