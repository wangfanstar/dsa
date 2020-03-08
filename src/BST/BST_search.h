/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> BinNodePosi(T) & BST<T>::search ( const T & e ) { //��BST�в��ҹؼ���e
   if ( !_root || e == _root->data ) { _hot = NULL; return _root; } //������v������
   for ( _hot = _root; ; ) { //�Զ�����
      BinNodePosi(T) & c = ( e < _hot->data ) ? _hot->lc : _hot->rc; //ȷ������
      if ( !c || e == c->data ) return c; _hot = c; //���з��أ���������һ��
   } //�������л�ʧ�ܣ�hot��ָ��v֮���ף���ΪNULL��
} //����Ŀ��ڵ�λ�õ����ã��Ա�������롢ɾ������
