/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T PQ_LeftHeap<T>::delMax() {
   BinNodePosi(T) lHeap = _root->lc; if (lHeap) lHeap->parent = NULL; //左子堆
   BinNodePosi(T) rHeap = _root->rc; if (rHeap) rHeap->parent = NULL; //右子堆
   T e = _root->data; delete _root; _size--; //删除根节点
   _root = merge ( lHeap, rHeap ); //合并原左、右子堆
   return e; //返回原根节点的数据项
}