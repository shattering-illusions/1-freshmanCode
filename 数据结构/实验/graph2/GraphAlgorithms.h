#pragma once
#include "GraphStruct.h"
#include <vector>

// 打印邻接表验证创建是否成功
void PrintAdjListGraph(const Graph& G);

//T1
int getEdgeNum(const Graph& G);

//T3
//实现函数firstAdj（G，v）和nextAdj(G,v,w)

int firstAdj(Graph& G, int v);
int nextAdj(Graph& G, int v,int w);

//T4
bool isDirectedTree(Graph& G, int v);
bool isGraphConnectedFrom(Graph& G, int v);
void dfs(Graph& G,const int v,std::vector<bool>& visited);
int getInDegreeList(const Graph& G, int v);

//T5
void visit(Graph G, int v);
void dfs_5(Graph& G, const int v, std::vector<bool>& visited);
void dfsSpanningTree(Graph& G, std::vector<std::vector<int>>& B);
