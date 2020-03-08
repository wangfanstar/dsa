#include "stack/stack.h" //借助栈结构，计算直方图H[]中的最大矩形（并列时取最靠左者）

__int64 mr_STACK( int H[], int n, int& mr_r, int& mr_s, int& mr_t ) { //H[]皆非负
   Stack<int> SR; //次栈顶、栈顶总是s[r]-1与r，当前的t = t[r]
   __int64 maxRect = 0;
   for ( int t = 0; t <= n; t++ ) { //逐个尝试以t为右边界的
      while ( !SR.empty() && ( t == n || H[SR.top()] > H[t] ) ) { //每一个极大矩形
         int r = SR.pop(); int s = SR.empty() ? 0 : SR.top() + 1;
         __int64 mR = H[r] * ( t - s );
         if ( maxRect < mR )
            { maxRect = mR; mr_r = r; mr_s = s; mr_t = t; }
      }
      if ( t < n ) SR.push( t ); //栈中只记录所有的H[s] = min{ H[k] | s <= k <= t } 
   } //assert: SR is empty at exit
   return maxRect;
} //每项进栈、出栈不过常数次，累计成本O(n)
