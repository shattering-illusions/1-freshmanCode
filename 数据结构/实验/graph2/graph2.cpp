// graph2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include "GraphStruct.h"
#include "GraphCreate.h"
#include "GraphAlgorithms.h"

int main()
{
    
    /*// 邻接表结构包含指针，虽然 VerList 大小不足以栈溢出，但养成好习惯仍可用 static
    static Graph myGraph;

    // 根据你实际文件的格式，选择调用不同的创建函数！
    // 如果文件是顶点对格式（如 A B 5），用 CreateGraphFromFile
    // 如果文件是矩阵格式（0 1 0 / 1 0 5 / 0 5 0），用 CreateGrpFromFile1

    const char* filePath = "grpData/udg8.grp";

    // 此处假设文件格式是顶点对，调用 CreateGraphFromFile
    if (CreateGraphFromFile((char*)filePath, myGraph)) {
        std::cout << "图创建成功！" << std::endl;
        PrintAdjListGraph(myGraph);

        // ?? 重要：邻接表使用了 new 分配内存，使用完毕后必须销毁！
        DestroyGraph(myGraph);
        std::cout << "图已销毁，内存已释放。" << std::endl;
    }
    else {
        std::cout << "图创建失败！" << std::endl;
    }
    
    udg8.grp
	udg115.grp
	dg6.grp
	f14.grp
*/

    static Graph myGraph1;
    static Graph myGraph2;
    static Graph myGraph3;
    static Graph myGraph4;
    static Graph myGraph5;
    static Graph myGraph6;
    static Graph myGraph7;
    static Graph myGraph8;
    static Graph myGraph9;

    const char* filePath1 = "grpData/udg8.grp";
    const char* filePath2 = "grpData/udg115.grp";
    const char* filePath3 = "grpData/dg6.grp";
    const char* filePath4 = "grpData/f14.grp";
    const char* filePath5 = "grpData/udTree11.grp";
    const char* filePath7 = "grpData/dTree11.grp";
    const char* filePath6 = "grpData/udg10.grp";
    const char* filePath8 = "grpData/udn6.grp";
    const char* filePath9 = "grpData/udn8.grp";


    if (CreateGraphFromFile((char*)filePath1, myGraph1)) 
    {
        //PrintAdjListGraph(myGraph1);
    }
    else 
    {
        std::cout << "图 1 创建失败！" << std::endl;
    }

    if (CreateGraphFromFile((char*)filePath2, myGraph2))
    {
        //PrintAdjListGraph(myGraph2);
    }
    else
    {
        std::cout << "图 2 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath3, myGraph3))
    {
        //PrintAdjListGraph(myGraph3);
    }
    else
    {
        std::cout << "图 3 创建失败！" << std::endl;
    }

    if (CreateGraphFromFile((char*)filePath4, myGraph4))
    {
        //PrintAdjListGraph(myGraph4);
    }
    else
    {
        std::cout << "图 4 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath5, myGraph5))
    {
        //PrintAdjListGraph(myGraph5);
    }
    else
    {
        std::cout << "图 5 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath6, myGraph6))
    {
        //PrintAdjListGraph(myGraph6);
    }
    else
    {
        std::cout << "图 6 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath7, myGraph7))
    {
        //PrintAdjListGraph(myGraph7);
    }
    else
    {
        std::cout << "图 7 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath8, myGraph8))
    {
        //PrintAdjListGraph(myGraph8);
    }
    else
    {
        std::cout << "图 8 创建失败！" << std::endl;
    }
    if (CreateGraphFromFile((char*)filePath9, myGraph9))
    {
        //PrintAdjListGraph(myGraph9);
    }
    else
    {
        std::cout << "图 9 创建失败！" << std::endl;
    }

    //T1
    std::cout << "------ 测试第一题 ------" << std::endl;
    std::cout << "图1边数为：" << getEdgeNum(myGraph1) << std::endl;
    std::cout << "图2边数为：" << getEdgeNum(myGraph2) << std::endl;
    std::cout << "图3边数为：" << getEdgeNum(myGraph3) << std::endl;
    std::cout << "图4边数为：" << getEdgeNum(myGraph4) << std::endl;
    //T3
    std::cout << "------ 测试第三题 ------" << std::endl;
    std::cout << "图1的firstAdj(G,1)为：" << firstAdj(myGraph1,1) << std::endl;
    std::cout << "图1的nextAdj(G,1,2)为：" << nextAdj(myGraph1, 1, 2) << std::endl;
    std::cout << "图2的firstAdj(G,1)为：" << firstAdj(myGraph2, 1) << std::endl;
    std::cout << "图2的nextAdj(G,1,2)为：" << nextAdj(myGraph2, 1, 2) << std::endl;
    std::cout << "图3的firstAdj(G,1)为：" << firstAdj(myGraph3, 1) << std::endl;
    std::cout << "图3的nextAdj(G,1,2)为：" << nextAdj(myGraph3, 1, 2) << std::endl;
    std::cout << "图4的firstAdj(G,1)为：" << firstAdj(myGraph4, 1) << std::endl;
    std::cout << "图4的nextAdj(G,1,2)为：" << nextAdj(myGraph4, 1, 2) << std::endl;

    //T4
    std::cout << "------ 测试第四题 ------" << std::endl;
    if (isDirectedTree(myGraph3, 1))
        std::cout << "图三是一棵以 1 为根的有向树" << std::endl;
    else
        std::cout << "图三不是一棵以 1 为根的有向树" << std::endl;
    if (isDirectedTree(myGraph7, 1))
        std::cout << "图七是一棵以 1 为根的有向树" << std::endl;
    else
        std::cout << "图七不是一棵以 1 为根的有向树" << std::endl;

    //T5
    std::cout << "------ 测试第五题 ------" << std::endl;

    std::vector<std::vector<int>> arr;

    dfsSpanningTree(myGraph6, arr);
    arr.assign(MaxVerNum + 1, std::vector<int>(MaxVerNum + 1, 0));
    dfsSpanningTree(myGraph5, arr);
    arr.assign(MaxVerNum + 1, std::vector<int>(MaxVerNum + 1, 0));

    dfsSpanningTree(myGraph8, arr);
    arr.assign(MaxVerNum + 1, std::vector<int>(MaxVerNum + 1, 0));

    dfsSpanningTree(myGraph9, arr);
    arr.assign(MaxVerNum + 1, std::vector<int>(MaxVerNum + 1, 0));






    //销毁
    DestroyGraph(myGraph1);
    DestroyGraph(myGraph2);
    DestroyGraph(myGraph3);
    DestroyGraph(myGraph4);
    DestroyGraph(myGraph5);
    DestroyGraph(myGraph6);
    DestroyGraph(myGraph7);
    DestroyGraph(myGraph8);
    DestroyGraph(myGraph9);

    return 0;
}
