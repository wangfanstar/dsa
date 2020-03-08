/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "rpn.h"
double calcu ( double a, char op, double b ) { //ִ�ж�Ԫ����
   switch ( op ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b; //ע�⣺����и�����Ϊ����ܲ���ȫ
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}

double calcu ( char op, double b ) { //ִ��һԪ����
   switch ( op ) {
      case '!' : return ( double ) facI ( ( int ) b ); //Ŀǰ���н׳ˣ����մ˷�ʽ���
      default  : exit ( -1 );
   }
}