/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

int sum ( int A[], int lo, int hi ) { //��������㷨�����ֵݹ�棬���Ϊsum(A, 0, n)��
   if ( hi - lo < 2 ) return A[lo]; //�ݹ���������Ȳ���2
   int mi = ( lo + hi ) >> 1; //�����򣩾���ԭ����
   return sum ( A, lo, mi ) + sum ( A, mi, hi ); //�ݹ���ͣ�Ȼ��ϼ�
} //O(hi - lo)����������������ĳ���