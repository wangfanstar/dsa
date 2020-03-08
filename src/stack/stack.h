/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2019. All rights reserved.
 ******************************************************************************************/

#pragma once

#if defined(DSA_STACK_VECTOR)
#include "stack_vector/stack_vector.h" //由向量派生的栈
#elif defined(DSA_STACK_LIST)
#include "stack_list/stack_list.h" //由列表派生的栈
#else
#endif
