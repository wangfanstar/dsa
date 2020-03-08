/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::delMax() {
   BinNodePosi(T) lHeap = _root->lc; if (lHeap) lHeap->parent = NULL; //���Ӷ�
   BinNodePosi(T) rHeap = _root->rc; if (rHeap) rHeap->parent = NULL; //���Ӷ�
   T e = _root->data; delete _root; _size--; //ɾ�����ڵ�
   _root = merge ( lHeap, rHeap ); //�ϲ�ԭ�����Ӷ�
   return e; //����ԭ���ڵ��������
}