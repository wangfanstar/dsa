/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int List<T>::deduplicate() {
   int oldSize = _size; ListNodePosi(T) p = first();
   for ( Rank r = 0; p != trailer; p = p->succ ) //O(n)
      if ( ListNodePosi(T) q = find(p->data, r, p) )
         remove(q); //��ʱq��p��ͬ����ɾ��ǰ�߸�Ϊ����
      else r++; //rΪ����ǰ׺�ĳ���
   return oldSize - _size; //ɾ��Ԫ������
}