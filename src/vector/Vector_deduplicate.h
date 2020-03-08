/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> int Vector<T>::deduplicate() { //ɾ�������������ظ�Ԫ�أ���Ч�棩
   int oldSize = _size; //��¼ԭ��ģ
   Rank i = 1; //��_elem[1]��ʼ
   while (i < _size) //��ǰ�����һ�����Ԫ��_elem[i]
      if (find(_elem[i], 0, i) < 0) //��ǰ׺[0,i)��Ѱ����֮��ͬ�ߣ�����һ����
         i++; //������ͬ�������������
      else
         remove(i); //����ɾ����ǰԪ��
   return oldSize - _size; //��ɾ��Ԫ������
}