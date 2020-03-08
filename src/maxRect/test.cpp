#include <stdlib.h>
#include <time.h>
#include <stdio.h>

__int64 mr_STACK ( int H[], int n, int& r, int& s, int& t ); //借助一个栈：O(n)
__int64 mr_STACKS( int H[], int n, int& r, int& s, int& t ); //借助两个栈：O(n)
__int64 mr_BRUTE ( int H[], int n, int& r, int& s, int& t ); //蛮力：O(n^2)

/******************************************************************************************
 * 直方图中的最大矩形
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   int* H; int n; //宽度为n的直方图
   if ( 1 < argc ) { //命令行指定，比如：77 4 120 16 96 59 0 15 123 8 79 73 57 96 84 101 26 12 88 81 111 18 87 117 46 90 94 70 125
      H = new int[ n = argc -1 ];
      for ( int i = 0; i < n; i++ )
         H[i] = atoi( argv[i+1] );
   } else { //随机生成
      srand ( ( unsigned int ) time ( NULL ) );
      H = new int[ 1 + ( n = rand() % 128 ) ];
      for ( int i = 0; i < n; i++ )
         H[i] = rand() % 128;
   }

   int r, s, t; //最大矩形：H[r] x [s, t)
   __int64 mrBrute = mr_BRUTE( H, n, r = -1, s = -1, t = -1 );
   printf( "MaxRect Brute-Force  : %I64d = %d x [%d,%d)\n", mrBrute, H[r], s, t );
   __int64 mrStacks = mr_STACKS( H, n, r = -1, s = -1, t = -1 );
   printf( "MaxRect using STACKS : %I64d = %d x [%d,%d)\n", mrStacks, H[r], s, t );
   __int64 mrStack  = mr_STACK ( H, n, r = -1, s = -1, t = -1 );
   printf( "MaxRect using STACK  : %I64d = %d x [%d,%d)\n", mrStack, H[r], s, t );

   for ( int i = 0; i < s; i++ ) {
      printf("%3d:%4d : ", i, H[i]);
      for ( int j = 0; j < H[i]; j++ ) printf("."); printf("\n");
   }
   for ( int i = s; i < r; i++ ) {
      printf("%3d:%4d : ", i, H[i]);
      for ( int j = 0; j < H[i]; j++ ) printf( (j < H[r]) ? "#" : "." ); printf("\n");
   }
   {
      printf("%3d:%4d : ", r, H[r]);
      for ( int j = 0; j < H[r]; j++ ) printf("O"); printf("\n");
   }
   for ( int i = r+1; i < t; i++ ) {
      printf("%3d:%4d : ", i, H[i]);
      for ( int j = 0; j < H[i]; j++ ) printf( (j < H[r]) ? "#" : "." ); printf("\n");
   }
   for ( int i = t; i < n; i++ ) {
      printf("%3d:%4d : ", i, H[i]);
      for ( int j = 0; j < H[i]; j++ ) printf("."); printf("\n");
   }

   delete [] H;
   return 0;
}
