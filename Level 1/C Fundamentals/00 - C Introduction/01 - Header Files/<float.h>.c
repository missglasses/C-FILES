
#include <stdio.h>
#include <float.h>


//PRINTING FLOATING-POINT LIMITS USING FLOAT HEADER
int main() {
  
  printf("Float radix: %d (for binary)\n\n", FLT_RADIX);
  
  //Precision
  printf("Decimal digits (FLT_DIG): %d\n", FLT_DIG);
  printf("Decimal digits (DBL_DIG) || min: 6: %d\n", DBL_DIG);
  printf("Decimal digits (LDBL_DIG) || min: 10: %d\n", LDBL_DIG);
   printf("Decimal digits (DECIMAL_DIG) || min: 10: %d\n\n", DECIMAL_DIG);
  
  printf("Float range: %e-%e\n", FLT_MIN, FLT_MAX);
  printf("Double range: %e-%e\n", DBL_MIN, DBL_MAX);
   printf("Long double range: %e-%e\n", LDBL_MIN, LDBL_MAX);
   
   
//   machine epsilon : FLT_EPSILON, DBL_EPSILON, LBDL_EPSILON

    printf("Rounding || Float : %d\n", FLT_ROUNDS);
  //other: FLT_EVAL_METHOD
  
  
  
  
    return 0;
}
