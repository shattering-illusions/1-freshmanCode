#include <iostream>
#include "GraphStruct.h"
#include "GraphAlgorithms.h"

void PrintGraphInfo(const Graph& G)
{
    std::cout << "------- ?????? -------" << std::endl;
    std::cout << "??????: " << G.VerNum << ", ????: " << G.ArcNum << std::endl;

    std::cout << "????????: ";
    for (int i = 1; i <= G.VerNum; ++i) {
        std::cout << G.data[i] << " ";
    }

    std::cout << "\n??????:\n";
    for (int i = 1; i <= G.VerNum; ++i) {
        for (int j = 1; j <= G.VerNum; ++j) {
            if (G.AdjMatrix[i][j] == INF) {
                std::cout << "INF\t";
            }
            else {
                std::cout << G.AdjMatrix[i][j] << "\t";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}


// T2
static bool DFSPath(const Graph& G, int vIdx, int wIdx, bool visited[])
{
    if (vIdx == wIdx)
        return true;

    visited[vIdx] = true;


    for (int i = 1; i <= G.VerNum; i++)
    {
        
        bool hasEdge = false;
        if (G.gKind == UDG || G.gKind == DG)
            hasEdge = (G.AdjMatrix[vIdx][i] != 0);     
        else
            hasEdge = (G.AdjMatrix[vIdx][i] != INF); 

        if (hasEdge && !visited[i])
        {
            if (DFSPath(G, i, wIdx, visited))
                return true;
        }
    }

    return false;
}

bool ifPass(const Graph& G, elementType v, elementType w)
{
    int vIdx = -1, wIdx = -1;
    for (int i = 1; i <= G.VerNum; i++)
    {
        if (G.data[i] == v) 
            vIdx = i;
        if (G.data[i] == w) 
            wIdx = i;
    }

    if (vIdx == -1 || wIdx == -1)
        return false;

    bool visited[MaxVerNum + 1] = { false };

    return DFSPath(G, vIdx, wIdx, visited);
}