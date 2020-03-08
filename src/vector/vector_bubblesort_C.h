/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //向量的起泡排序（跳跃版）
void Vector<T>::bubbleSort( Rank lo, Rank hi ) { //assert: 0 <= lo < hi <= size
   for( Rank last = --hi; lo < hi; hi = last )
      for( Rank i = last = lo; i < hi; i++ )
         if( _elem[i] > _elem[i + 1] ) //若逆序，则
            swap( _elem[ last = i ], _elem[ i + 1 ] ); //经交换使局部有序
}
