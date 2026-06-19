#pragma once
#include "GraphStruct.h" // 需要包含 Graph 定义，因为参数用到了 Graph

// 声明从文件创建图的函数
bool CreateGrpFromFile(char fileName[], Graph& G);

