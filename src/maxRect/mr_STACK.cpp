#include "stack/stack.h" //����ջ�ṹ������ֱ��ͼH[]�е������Σ�����ʱȡ����ߣ�

__int64 mr_STACK( int H[], int n, int& mr_r, int& mr_s, int& mr_t ) { //H[]�ԷǸ�
   Stack<int> SR; //��ջ����ջ������s[r]-1��r����ǰ��t = t[r]
   __int64 maxRect = 0;
   for ( int t = 0; t <= n; t++ ) { //���������tΪ�ұ߽��
      while ( !SR.empty() && ( t == n || H[SR.top()] > H[t] ) ) { //ÿһ���������
         int r = SR.pop(); int s = SR.empty() ? 0 : SR.top() + 1;
         __int64 mR = H[r] * ( t - s );
         if ( maxRect < mR )
            { maxRect = mR; mr_r = r; mr_s = s; mr_t = t; }
      }
      if ( t < n ) SR.push( t ); //ջ��ֻ��¼���е�H[s] = min{ H[k] | s <= k <= t } 
   } //assert: SR is empty at exit
   return maxRect;
} //ÿ���ջ����ջ���������Σ��ۼƳɱ�O(n)
