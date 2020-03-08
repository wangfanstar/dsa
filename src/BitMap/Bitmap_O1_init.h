/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

#pragma warning(disable : 4996 4800)
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include "_share/release.h"

class Bitmap { //λͼBitmap�ࣺ�Կռ���Ϊ��������ʡ��ʼ��ʱ�䣨��������룬��֧��ɾ����
private:
   Rank* F; Rank N; //��ģΪN������F����¼[k]����ǵĴ��򣨼�����ջT[]�е��ȣ�
   Rank* T; Rank top; //����ΪN��ջT����¼����Ǹ�λ�ȵ�ջ���Լ�ջ��ָ��

public:
   Bitmap ( Rank n = 8 ) //��ָ������Ĭ�ϣ���ģ��������ͼ��Ϊ������ʱѡ�ý�С��Ĭ��ֵ��
   { N = n; F = new Rank[N]; T = new Rank[N]; top = 0; } //��O(1)ʱ������ʽ�س�ʼ��
   ~Bitmap() { delete [] F; delete [] T; } //����ʱ�ͷſռ�

// �ӿ�
   inline void reset() { top = 0; } //��λ�����߼����ж�����У�黷��O(1)
   inline void set ( Rank k ) { //���룺���߼��Ͻ�B[k]��Ϊtrue��O(1)
      if ( ! test ( k ) ) { //�����Ѵ���ǵ�λ
         T[ top ] = k; F[ k ] = top++; //����У�黷
      }
   }
   inline void clear( Rank k ) { //ɾ�������߼��Ͻ�B[k]��Ϊfalse��O(1)
      if ( test ( k ) ) //���Բ�����ǵ�λ
         if ( --top ) { //���У�黷��ͬʱ����ջT�Ŀ��е�Ԫ������Կ�ջ�Ĵ���
            F[ T[ top ] ] = F[ k ]; T[ F[ k ] ] = T[ top ];
         }
   }
   inline bool test( Rank k ) //���߼����ж�B[k]�Ƿ�Ϊtrue��O(1)
   {  return ( -1 < F[ k ] ) && ( F[ k ] < top ) && ( k == T[ F[ k ] ] );  }
};
