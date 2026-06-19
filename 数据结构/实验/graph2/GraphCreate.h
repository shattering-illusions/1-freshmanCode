#pragma once
#include "GraphStruct.h"

// 从邻接矩阵格式文件创建图
int CreateGrpFromFile1(char fileName[], Graph& G);

// 从顶点对（边）格式文件创建图
int CreateGraphFromFile(char fileName[], Graph& G);

// 销毁图，释放内存
void DestroyGraph(Graph& G);

