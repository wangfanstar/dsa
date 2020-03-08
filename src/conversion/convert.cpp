/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

/*DSA*/#include "convert.h"

void convert ( Stack<char>& S, __int64 n, int base ) { //整数n的1<base<=16进制打印（迭代版）
   char digit[] = "0123456789ABCDEF"; //数位符号，如有必要可相应扩充
   while ( n > 0 ) { //由低到高，逐一计算出新进制下的各数位
      /*DSA*/printf ( "%20I64d = %20I64d * %d + %20I64d\n", n , n/base, base, n%base );
      S.push ( digit[ n % base ] ); //余数（当前位）入栈
      n /= base; //n更新为其对base的除商
      /*DSA*/print ( S ); getchar();
   }
} //新进制下由高到低的各数位，自顶而下保存于栈S中