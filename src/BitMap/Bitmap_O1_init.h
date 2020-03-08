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

class Bitmap { //位图Bitmap类：以空间作为补偿，节省初始化时间（既允许插入，亦支持删除）
private:
   Rank* F; Rank N; //规模为N的向量F，记录[k]被标记的次序（即其在栈T[]中的秩）
   Rank* T; Rank top; //容量为N的栈T，记录被标记各位秩的栈，以及栈顶指针

public:
   Bitmap ( Rank n = 8 ) //按指定（或默认）规模创建比特图（为测试暂时选用较小的默认值）
   { N = n; F = new Rank[N]; T = new Rank[N]; top = 0; } //在O(1)时间内隐式地初始化
   ~Bitmap() { delete [] F; delete [] T; } //析构时释放空间

// 接口
   inline void reset() { top = 0; } //复位：从逻辑上切断所有校验环，O(1)
   inline void set ( Rank k ) { //插入：从逻辑上将B[k]置为true，O(1)
      if ( ! test ( k ) ) { //忽略已带标记的位
         T[ top ] = k; F[ k ] = top++; //创建校验环
      }
   }
   inline void clear( Rank k ) { //删除：从逻辑上将B[k]置为false，O(1)
      if ( test ( k ) ) //忽略不带标记的位
         if ( --top ) { //清除校验环，同时回收栈T的空闲单元（留意对空栈的处理）
            F[ T[ top ] ] = F[ k ]; T[ F[ k ] ] = T[ top ];
         }
   }
   inline bool test( Rank k ) //从逻辑上判断B[k]是否为true，O(1)
   {  return ( -1 < F[ k ] ) && ( F[ k ] < top ) && ( k == T[ F[ k ] ] );  }
};
