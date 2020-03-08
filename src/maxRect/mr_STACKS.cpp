#include "stack/stack.h" //����ջ�ṹ������ֱ��ͼH[]�е������Σ�����ʱȡ����ߣ�

__int64 mr_STACKS( int H[], int n, int& mr_r, int& mr_s, int& mr_t ) { //��ĩ��-1�ڱ���H[]�ԷǸ�
   int* s = new int[n]; Stack<int> S; //���ҿɼ������
   for( int r = 0; r < n; r++ ) { //���μ����
      while ( !S.empty() && H[S.top()] >= H[r] ) S.pop(); //ÿһ��s(r)
      s[r] = S.empty() ? 0 : 1 + S.top();
      S.push(r);
   }
   while( !S.empty() ) S.pop();

   int* t = new int[n]; Stack<int> T; //����ɼ������
   for( int r = n-1; -1 < r; r-- ) { //���μ����
      while ( !T.empty() && H[r] <= H[T.top()] ) T.pop(); //ÿһ��t(r)
      t[r] = T.empty() ? n : T.top();
      T.push(r);
   }
   while( !T.empty() ) T.pop();

   __int64 maxRect = 0;
   for( int r = 0; r < n; r++ ) {
      __int64 mR = H[r] * (t[r] - s[r]);
      if ( maxRect < mR )
         { maxRect = mR; mr_r = r; mr_s = s[r]; mr_t = t[r]; }
   }
   delete [] s; delete [] t;
   return maxRect;
} //ÿ���ջ����ջ���������Σ��ۼƳɱ�O(n)
