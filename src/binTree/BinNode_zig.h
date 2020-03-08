/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) BinNode<T>::zig() { //˳ʱ����ת
   BinNodePosi(T) lChild = lc;
   lChild->parent = this->parent;
   if ( lChild->parent )
      ( ( this == lChild->parent->rc ) ? lChild->parent->rc : lChild->parent->lc ) = lChild;
   lc = lChild->rc; if ( lc ) lc->parent = this;
   lChild->rc = this; this->parent = lChild;
// update heights ()
   height = 1 + __max ( stature ( lc ), stature ( rc ) );
   lChild->height = 1 + __max ( stature ( lChild->lc ), stature ( lChild->rc ) );
   for ( BinNodePosi(T) x = lChild->parent; x; x = x->parent )
      if ( HeightUpdated( *x ) )
         break;
      else
         x->height = 1 + __max ( stature ( x->lc ), stature ( x->rc ) );
   return lChild;
}
