// �����������ؼ���ֱ��ͼH[]�е������Σ��������ʱȡ�����ߣ�
__int64 mr_BRUTE( int H[], int n, int& mr_r, int& mr_s, int& mr_t ) { //������O(n^2)
   __int64 maxRect = 0;
   for ( int r = 0, s = 0, t = 0; r < n; r++, s = t = r ) {
      do s--; while ( -1 < s  &&  H[s] >= H[r] ); s++;
      do t++; while ( t < n   &&  H[r] <= H[t] );
      __int64 rect = (__int64) H[r] * ( t - s );
      if ( maxRect < rect )
         { maxRect = rect; mr_r = r; mr_s = s; mr_t = t; }
   }
   return maxRect;
} //ÿ��������κ�ʱO(n)���ۼ�O(n^2)
