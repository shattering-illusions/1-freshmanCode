#include <iostream>
#include <vector>
#include "GraphAlgorithms.h"

void PrintAdjListGraph(const Graph& G)
{
    std::cout << "------- 邻接表图的信息 -------" << std::endl;
    std::cout << "顶点数: " << G.VerNum << ", 边数: " << G.ArcNum << std::endl;

    for (int i = 1; i <= G.VerNum; ++i) {
        std::cout << "顶点 " << G.VerList[i].data << " -> ";
        EdgeNode* p = G.VerList[i].firstEdge;
        while (p != NULL) {
            std::cout << "[邻接点:" << G.VerList[p->adjVer].data << ", 权:" << p->eInfo << "] -> ";
            p = p->next;
        }
        std::cout << "NULL" << std::endl;
    }
    std::cout << "------------------------------" << std::endl;
}

//T1

int getEdgeNum(const Graph& G)
{
    int totalEdgeNodes = 0;

    for (int i = 1; i <= G.VerNum; ++i)
    {
        EdgeNode* p = G.VerList[i].firstEdge;
        while (p != NULL)
        {
            totalEdgeNodes++;
            p = p->next;
        }
    }

    if (G.gKind == UDG || G.gKind == UDN)
        return totalEdgeNodes / 2;
    else  // DG 或 DN
        return totalEdgeNodes;

   
}

//T3
int firstAdj(Graph& G, int v)
{
    EdgeNode* p = G.VerList[v].firstEdge;
    if (p != nullptr)
        return p->adjVer;
    else
        return -1;
}

int nextAdj(Graph& G, int v, int w)
{
    EdgeNode* p = G.VerList[v].firstEdge;
    while (p != nullptr && p->adjVer != w)
    {
        p = p->next;
    }
    if (p != nullptr && p->next != nullptr)
    {
        return p->next->adjVer;
    }
    return -1;
}

//T4

bool isDirectedTree(Graph& G, int v)
{
    if (G.gKind == UDG || G.gKind == UDN)
        return false;
    if (!(G.ArcNum == (G.VerNum - 1)))
        return false;

    if (!isGraphConnectedFrom(G, v))
        return false;

    for (int i = 1; i <= G.VerNum; ++i)
    {
        int indeg = getInDegreeList(G, i);
        if (i == v && indeg != 0)
            return false;
        else if (i != v && indeg != 1 )
            return false;
        else
            continue;
    }
    return true;
}

bool isGraphConnectedFrom(Graph& G, int v)//借助深度搜索遍历整图，判断图是否连通分量为 1
{
    std::vector<bool> visited(G.VerNum + 1, false);
    dfs(G, v, visited);
    for (int i = 1; i <= G.VerNum; ++i)    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(Graph& G,const int v, std::vector<bool>& visited)//深度搜索
{
    
    visited[v] = true;
    int w = firstAdj(G, v);
    while (w != -1)
    {
        if (!visited[w])
            dfs(G, w, visited);
        w = nextAdj(G, v, w);
    }
}

int getInDegreeList(const Graph& G, int v)//给一个顶点，输出该顶点的度数
{
    int inDegree = 0;
    for (int i = 1; i <= G.VerNum; ++i)
    {
        EdgeNode* p = G.VerList[i].firstEdge;
        while (p != nullptr)
        {
            if (p->adjVer == v) 
            {
                inDegree++;
                break;
            }
            p = p->next;
        }
    }
    return inDegree;
}

//T5
void visit(Graph G, int v)
{
    std::cout << G.VerList[v].data << " ";
}

static std::vector<int>* TreeB = nullptr;

void dfs_5(Graph& G, const int v, std::vector<bool>& visited)//深度搜索，同时记录DFS生成树边到TreeB
{
    visit(G, v);
    visited[v] = true;
    for (EdgeNode* p = G.VerList[v].firstEdge; p != nullptr; p = p->next)
    {
        int w = p->adjVer;
        if (!visited[w])
        {
            // 记录树边 v -> w 到邻接矩阵
            TreeB[v][w] = p->eInfo;
            // 无向图需要对称存储
            if (G.gKind == UDG || G.gKind == UDN)
                TreeB[w][v] = p->eInfo;
            dfs_5(G, w, visited);
        }
    }
}

void dfsSpanningTree(Graph& G, std::vector<std::vector<int>>& B)
{
    // 将矩阵B分配为 (VerNum+1) x (VerNum+1) 并清零
    B.assign(MaxVerNum + 1, std::vector<int>(MaxVerNum + 1, 0));

    TreeB = B.data();// 将文件静态指针指向B的内部连续存储，供dfs_5使用

    std::vector<bool> visited(G.VerNum + 1, false);
    dfs_5(G, 1, visited);
    std::cout << "\n";
    TreeB = nullptr;
}