#include <stdlib.h>

extern int s_lo, s_hi;

int gs_DC( int A[], int lo, int hi ) { //���β��ԣ�O(n*logn)
   if ( hi - lo < 2 ) return A[lo];
   int mi = (lo + hi) / 2;

   int gsL = A[mi-1], sL = 0, i = mi; //ö��
   while ( lo < i-- ) //����[i, mi)������
      if ( gsL < (sL += A[i]) ) gsL = sL;

   int gsR = A[mi], sR = 0, j = mi-1; //ö��
   while ( ++j < hi ) //����[mi, j)������
      if ( gsR < (sR += A[j]) ) gsR = sR; //���š�����

   return __max( gsL + gsR, __max( gs_DC( A, lo, mi ), gs_DC( A, mi, hi ) ) ); //�ݹ�
}