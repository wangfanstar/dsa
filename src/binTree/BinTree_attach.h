/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

/*DSA*/template <typename T> //二叉树子树接入算法：将S当作节点x的左子树接入，S本身置空
/*DSA*/BinNodePosi(T) BinTree<T>::attachAsLC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->lc == NULL
/*DSA*/   if ( x->lc = S->_root ) x->lc->parent = x; //接入
/*DSA*/   _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
/*DSA*/   S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
/*DSA*/}
/*DSA*/
template <typename T> //二叉树子树接入算法：将S当作节点x的右子树接入，S本身置空
BinNodePosi(T) BinTree<T>::attachAsRC ( BinNodePosi(T) x, BinTree<T>* &S ) { //x->rc == NULL
   if ( x->rc = S->_root ) x->rc->parent = x; //接入
   _size += S->_size; updateHeightAbove ( x ); //更新全树规模与x所有祖先的高度
   S->_root = NULL; S->_size = 0; release ( S ); S = NULL; return x; //释放原树，返回接入位置
} //attachAsLC()完全对称，在此省略；release()负责释放复杂结构，与算法无直接关系，具体实现详见代码包
