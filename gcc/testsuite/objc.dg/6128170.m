/* APPLE LOCAL file 6128170 */
/* { dg-do compile { target i?86*-*-darwin* x86_64-*-darwin* } } */
/* { dg-options { "-m64" } } */
/* { dg-final { scan-assembler "GCC_except_table.*:\nLLSDA" } } */
/* { dg-final { scan-assembler-not "GCC_except_table.*:\n\t.align" } } */
#include <Foundation/Foundation.h>
void test()
{
  @try {
    [NSObject alloc];
  }
  @catch (NSException* ex) {
    [NSObject alloc];
  }
}
