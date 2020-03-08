#include <stdlib.h>

extern int s_lo, s_hi;

int gs_DC( int A[], int lo, int hi ) { //分治策略：O(n*logn)
   if ( hi - lo < 2 ) return A[lo];
   int mi = (lo + hi) / 2;

   int gsL = A[mi-1], sL = 0, i = mi; //枚举
   while ( lo < i-- ) //所有[i, mi)类区段
      if ( gsL < (sL += A[i]) ) gsL = sL;

   int gsR = A[mi], sR = 0, j = mi-1; //枚举
   while ( ++j < hi ) //所有[mi, j)类区段
      if ( gsR < (sR += A[j]) ) gsR = sR; //择优、更新

   return __max( gsL + gsR, __max( gs_DC( A, lo, mi ), gs_DC( A, mi, hi ) ) ); //递归
}