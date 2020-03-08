/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

/******************************************************************************************
 * 将vector各方法的实现部分，简洁地引入vector.h
 * 效果等同于将这些实现直接汇入vector.h
 * 在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
 ******************************************************************************************/
#include "_share/release.h"
#include "_share/util.h"

#include "vector_bracket.h"
#include "vector_assignment.h"

#include "vector_constructor_by_copying.h"

#include "vector_expand.h"
#include "vector_shrink.h"

#include "Vector_insert.h"
#include "vector_remove.h"
#include "vector_removeInterval.h"

#include "Vector_find.h"
#include "Vector_search.h"
#include "Vector_search_binary_C.h" //有A、B、C三种版本，C最完善
//#include "Vector_search_fibonaccian_A.h" //实用版（但返回值有待与接口统一）
#include "Vector_search_fibonaccian_B.h" //华丽版

#include "Vector_traverse.h"

#include "Vector_unsort.h"
#include "Vector_sort.h"
//#include "vector_bubbleSort_A.h"
//#include "vector_bubbleSort_B.h"
#include "vector_bubbleSort_C.h"
#include "vector_selectionSort.h"
#include "vector_merge.h"
#include "vector_mergeSort.h"
//#include "vector_partition_A.h"
//#include "vector_partition_A1.h"
//#include "vector_partition_B.h"
//#include "vector_partition_B1.h"
#include "vector_partition_C.h"
#include "vector_heapSort.h"
#include "vector_quickSort.h"
#include "vector_shellSort.h"

#include "Vector_uniquify.h" //或者Vector_uniquify_slow.h
#include "Vector_deduplicate.h"
