/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

//�ӵ�ǰ�ڵ�����������֧�������룬ֱ��û�����֧�Ľڵ㣻��;�ڵ���������������
template <typename T, typename VST> //Ԫ�����͡�������
static void visitAlongVine ( BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S ) {
   while ( x ) {
      visit ( x->data ); //���ʵ�ǰ�ڵ�
      S.push ( x->rc ); //�Һ�����ջ�ݴ棨���Ż���ͨ���жϣ�����յ��Һ�����ջ��
      x = x->lc;  //�����֧����һ��
   }
}

template <typename T, typename VST> //Ԫ�����͡�������
void travPre_I2 ( BinNodePosi(T) x, VST& visit ) { //��������������㷨��������#2��
   Stack<BinNodePosi(T)> S; //����ջ
   while ( true ) {
      visitAlongVine ( x, visit, S ); //�ӵ�ǰ�ڵ��������������
      if ( S.empty() ) break; //ֱ��ջ��
      x = S.pop(); //������һ�������
   }
}