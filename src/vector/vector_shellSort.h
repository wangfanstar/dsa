/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //ÏòÁ¿Ï£¶ûÅÅÐò
void Vector<T>::shellSort ( Rank lo, Rank hi ) { //0 <= lo < hi <= size <= 2^30
   /*DSA*/ printf ( "\tSHELLsort [%3d, %3d)\n", lo, hi );
   for ( int d = 0x3FFFFFFF; 0 < d; d >>= 1 ) //PS Sequence: { 1, 3, 7, 15, ..., 1073741823 }
      for ( int j = lo + d; j < hi; j++ ) { //for each j in [lo+d, hi)
         T x = _elem[j]; int i = j - d;
         while ( lo <= i && _elem[i] > x )
            { _elem[i + d] = _elem[i]; i -= d; }
         _elem[i + d] = x; //insert [j] into its subsequence
      }
}