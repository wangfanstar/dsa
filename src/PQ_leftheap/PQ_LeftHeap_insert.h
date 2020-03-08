/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> void PQ_LeftHeap<T>::insert ( T e ) {
   _root = merge( _root, new BinNode<T>( e, NULL ) ); //��e��װΪ��ʽ�ѣ��뵱ǰ��ʽ�Ѻϲ�
   _size++; //���¹�ģ
}