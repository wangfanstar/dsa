/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

//������ǰn�������еĵ�i��ʵʩ���ˣ�i < n
template <typename T> Rank percolateDown ( T* A, Rank n, Rank i ) {
   Rank j; //i���䣨���������������У���Ϊ����
   while ( i != ( j = ProperParent ( A, n, i ) ) ) //ֻҪi��j����
      { swap ( A[i], A[j] ); i = j; } //���߻�λ�������������½����i
   return i; //�������˵ִ��λ�ã���i��j��
}
