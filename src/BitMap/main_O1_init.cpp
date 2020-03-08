/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma warning(disable : 4996 4800)
#include "_share/util.h"
#include "Bitmap_O1_init.h"

/******************************************************************************************
 * ����λͼ
 ******************************************************************************************/
int testBitmap ( int n ) {
   bool* B = new bool[n]; //����λͼ
   Bitmap M ( n ); //��Чλͼ
   for ( int t = 0; t < 50; t++ ) { //�ظ�ʹ��λͼ���
      memset ( B, 0, n * sizeof ( bool ) ); //��λ���㣬O(n)
      M.reset(); //�߼����㣬O(1)
      for ( int i = 0; i < 3 * n; i++ ) { //������
         Rank k = dice ( n ); //�����λ����
         if ( dice ( 2 ) ) { //��50%�ĸ��ʲ���
            B[k] = true; M.set ( k );
         } else { //��50%�ĸ������
            B[k] = false; M.clear ( k );
         }
      }
      //M.set( 29 ); //��ʱ�������������Է�����Ա����Գ���
      int k;
      for ( k = 0; k < n; k++ ) //��λ�ضԱ�
         if ( B[k] != M.test ( k ) ) //һ�����ֲ���
            break; //�漴�˳�
      if ( k < n ) { //�����棨assert:: k == n+1��
         printf ( "\n B[]: " );
         for ( int j = 0; j <= k; j++ ) printf ( "%6c", B[j] ? 'x' : ' ' );
         printf ( "\n M[]: " );
         for ( int j = 0; j <= k; j++ ) printf ( "%6c", M.test ( j ) ? 'x' : ' ' );
         printf ( "\n" );
      } else
         printf( "Test %4d OK\n", t );
   }
   delete [] B;
   return 0;
}

/******************************************************************************************
 * ����λͼ
 ******************************************************************************************/
int main ( int argc, char* argv[] ) {
   if ( 2 > argc ) { printf ( "Usage: %s <size of test>\a\a\n", argv[0] ); return 1; }
   srand ( ( unsigned int ) time ( NULL ) ); //�����������
   return testBitmap ( atoi ( argv[1] ) ); //��������
}