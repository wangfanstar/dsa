extern int s_lo, s_hi;

int gs_IC( int A[], int n ) { //�������ԣ�O(n^2)
   int gs = A[0]; s_lo = n; s_hi = -1;
   for ( int i = 0; i < n; i++ ) { //ö��������ʼ��i
      int s = 0;
      for ( int j = i; j < n; j++ ) { //��ֹ��j������
         s += A[j]; //�����صõ����ܺͣ�O(1)
         if ( gs < s ) { gs = s; s_lo = i; s_hi = j + 1; } //���š�����
      }
   }
   return gs;
}
