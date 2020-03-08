/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "conversion/convert.h"

void convert ( Stack<char>& S, __int64 n, int base ) { //����n��1<base<=16���ƴ�ӡ���ݹ�棩
   static char digit[] = "0123456789ABCDEF"; //��λ���ţ����б�Ҫ����Ӧ����
   if ( 0 < n ) { //����������֮ǰ��������
      S.push ( digit[n % base] ); //�����¼��ǰ���λ����
      convert ( S, n / base, base ); //ͨ���ݹ�õ����и���λ
   }
} //�½������ɸߵ��͵ĸ���λ���Զ����±�����ջS��