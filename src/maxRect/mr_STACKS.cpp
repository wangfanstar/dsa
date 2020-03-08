#include "stack/stack.h" //借助栈结构，计算直方图H[]中的最大矩形（并列时取最靠左者）

__int64 mr_STACKS( int H[], int n, int& mr_r, int& mr_s, int& mr_t ) { //除末项-1哨兵，H[]皆非负
   int* s = new int[n]; Stack<int> S; //自右可见项的秩
   for( int r = 0; r < n; r++ ) { //依次计算出
      while ( !S.empty() && H[S.top()] >= H[r] ) S.pop(); //每一个s(r)
      s[r] = S.empty() ? 0 : 1 + S.top();
      S.push(r);
   }
   while( !S.empty() ) S.pop();

   int* t = new int[n]; Stack<int> T; //自左可见项的秩
   for( int r = n-1; -1 < r; r-- ) { //依次计算出
      while ( !T.empty() && H[r] <= H[T.top()] ) T.pop(); //每一个t(r)
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
} //每项进栈、出栈不过常数次，累计成本O(n)
