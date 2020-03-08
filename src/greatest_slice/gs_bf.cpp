extern int s_lo, s_hi;

int gs_BF( int A[], int n ) { //蛮力策略：O(n^3)
   int gs = A[0]; s_lo = n; s_hi = -1;
   for ( int i = 0; i < n; i++ )
      for ( int j = i; j < n; j++ ) { //枚举所有的O(n^2)个区段
         int s = 0; for ( int k = i; k <= j; k++ ) s += A[k]; //用O(n)时间求和
         if ( gs < s ) { gs = s; s_lo = i; s_hi = j + 1; } //择优、更新
      }
   return gs;
}
