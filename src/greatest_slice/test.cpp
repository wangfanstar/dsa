#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int s_lo, s_hi;

int gs_LS( int A[], int n ); //扫描策略：O(n)
int gs_DC( int A[], int lo, int hi ); //分治策略：O(n*logn)
int gs_IC( int A[], int n ); //递增策略：O(n^2)
int gs_BF( int A[], int n ); //蛮力策略：O(n^3)

/******************************************************************************************
 * 最大片段
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   int* A; int n;
   if ( 1 < argc ) { //命令行指定：-123 89 -86 -50 -63 88 -56 -5 31 112 106 72 17 127 -92 76 124 24 -54 19 -93 121 -28 11 24 -56 92 57 -16
      n = argc-1; A = new int[n];
      for ( int i = 0; i < n; i++ )
         A[i] = atoi( argv[i+1] );
   } else { //随机生成
      srand ( ( unsigned int ) time ( NULL ) );
      n = rand() % 128; A = new int[n];
      for ( int i = 0; i < n; i++ )
         A[i] = rand() % 128 - rand() % 96;
   }
   for ( int i = 0; i < n; i++ )
      printf("%3d:%4d\n", i, A[i]);
   printf( "GreatestSlice by Linear Scan:\t\t%d", gs_LS( A, n ) ); printf( "\t%d\t%d\n", s_lo, s_hi );
   printf( "GreatestSlice by Divide-And-Conquer:\t%d\n", gs_DC( A, 0, n ) );
   printf( "GreatestSlice by Incremental:\t\t%d", gs_IC( A, n ) ); printf( "\t%d\t%d\n", s_lo, s_hi );
   printf( "GreatestSlice by Brute-Force:\t\t%d", gs_BF( A, n ) ); printf( "\t%d\t%d\n", s_lo, s_hi );
   delete [] A;
   return 0;
}
