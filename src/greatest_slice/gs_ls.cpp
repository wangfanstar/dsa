extern int s_lo, s_hi;

int gs_LS( int A[], int n ) { //ɨ����ԣ�O(n)
   int gs = A[0], s = 0, i = n, j = n;
   while ( 0 < i-- ) { //���ڵ�ǰ����[i,j)
      s += A[i]; //�����صõ����ܺͣ�O(1)
      if ( gs < s ) { gs = s; s_lo = i; s_hi = j; } //���š�����
      if ( s <= 0 ) { s = 0; j = i; } //�������ͺ�׺
   }
   return gs;
}
