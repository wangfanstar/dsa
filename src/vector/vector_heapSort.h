/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void Vector<T>::heapSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size
   /*DSA*/ //printf ( "\tHEAPsort [%3d, %3d)\n", lo, hi );
   T* A = _elem + lo; Rank n = hi - lo; heapify( A, n ); //将待排序区间建成一个完全二叉堆，O(n)
   while ( 0 < --n ) //反复地摘除最大元并归入已排序的后缀，直至堆空
      { swap( A[0], A[n] ); percolateDown( A, n, 0 ); } //堆顶与末元素对换，再下滤
}
