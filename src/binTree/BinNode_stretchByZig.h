/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

//ͨ��zig��ת��������BST����x��������Ҳ�ͨ·
template <typename T> void stretchByZig ( BinNodePosi(T) & x ) {
   /*DSA*/   int c = 0; //��¼��ת����
   BinNodePosi(T) v = x;
   while ( x->lc ) x = x->lc;
   for ( ; v; v = v->rc ) {
      while ( v->lc )
         /*DSA*/{
         v = v->zig();
         /*DSA*/c++;
         /*DSA*/}
   }
   /*DSA*/printf ( "\nsize = %d, height = %d, #zig = %d\n\n", x->size(), x->height, c );
}
