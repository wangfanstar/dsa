/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

#include "fibonacci/Fib.h" //����Fib������
// Fibonacci�����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e��0 <= lo <= hi <= _size
template <typename T> static Rank fibSearch ( T* S, T const& e, Rank lo, Rank hi ) {
   /*DSA*/printf ( "FIB search (A)\n" );
    //��O(log_phi(n = hi - lo)ʱ�䴴��Fib����
   for ( Fib fib ( hi - lo ); lo < hi; ) {  //Fib�����Ʊ��飻�˺�ÿ��������һ�αȽϡ�������֧
      /*DSA*/ for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); else printf ( "<<<<|" ); printf ( "\n" );
      while ( hi - lo < fib.get() ) fib.prev(); //�Ժ���ǰ˳����ң���̯O(1)��
      Rank mi = lo + fib.get() - 1; //ȷ������Fib(k) - 1�����
      if      ( e < S[mi] ) hi = mi; //����ǰ���[lo, mi)��������
      else if ( S[mi] < e ) lo = mi + 1; //�������(mi, hi)��������
      else                  return mi; //��mi������
      /*DSA*/ if ( lo >= hi ) { for ( int i = 0; i < mi; i++ ) printf ( "     " ); if ( mi >= 0 ) printf ( "....|\n" ); else printf ( "<<<<|\n" ); }
   } //�ɹ����ҿ�����ǰ��ֹ
   return -1; //����ʧ��
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��