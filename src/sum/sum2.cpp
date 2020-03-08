/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

int sum ( int A[], int lo, int hi ) { //数组求和算法（二分递归版，入口为sum(A, 0, n)）
   if ( hi - lo < 2 ) return A[lo]; //递归基：区间宽度不足2
   int mi = ( lo + hi ) >> 1; //（否则）均分原区间
   return sum ( A, lo, mi ) + sum ( A, mi, hi ); //递归求和，然后合计
} //O(hi - lo)，线性正比于区间的长度