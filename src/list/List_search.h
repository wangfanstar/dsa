/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�������e�������
ListNodePosi(T) List<T>::search ( T const& e, int n, ListNodePosi(T) p ) const {
// assert: 0 <= n <= rank(p) < _size
   /*DSA*/printf ( "searching for " ); print ( e ); printf ( " :\n" );
   do {
      p = p->pred; n--;  //��������
      /*DSA*/  printf ( " -->%4d", p->data );
   } while ( ( -1 < n ) && ( e < p->data ) ); //����Ƚϣ�ֱ�����л�Խ��
   /*DSA*/  printf ( "\n" );
   return p; //���ز�����ֹ��λ��
} //ʧ��ʱ������������߽��ǰ����������header�����������߿�ͨ��valid()�жϳɹ����