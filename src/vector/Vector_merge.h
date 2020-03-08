/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> //�������������䣩�Ĺ鲢
void Vector<T>::merge ( Rank lo, Rank mi, Rank hi ) { //���������������[lo, mi)��[mi, hi)
   T* A = _elem + lo; //�ϲ��������A[0, hi - lo) = _elem[lo, hi)
   int lb = mi - lo; T* B = new T[lb]; //ǰ������B[0, lb) = _elem[lo, mi)
   for ( Rank i = 0; i < lb; i++ ) B[i] = A[i]; //����ǰ������
   int lc = hi - mi; T* C = _elem + mi; //��������C[0, lc) = _elem[mi, hi)
   for ( Rank i = 0, j = 0, k = 0; j < lb; ) //�鲢��������B��C��Ԫ����ȡ����С��
      A[i++] = ( lc <= k || B[j] <= C[k] ) ? B[j++] : C[k++]; //�������A��
   delete [] B; //�ͷ���ʱ�ռ�B
}
