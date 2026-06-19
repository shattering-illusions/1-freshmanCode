// graph1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include "GraphStruct.h"
#include "GraphCreate.h"
#include "GraphAlgorithms.h"

//Graph myGraph;

int main()
{
    /*// 使用相对路径：同级目录下的 grpData 文件夹中的 udg8.grp 文件
    // 注意：在C++字符串中，可以使用正斜杠(/)作为路径分隔符，也可以使用双反斜杠(\\)
    const char* filePath = "grpData/udg8.grp";

    if (CreateGrpFromFile((char*)filePath, myGraph)) {
        std::cout << "图创建成功！" << std::endl;
        PrintGraphInfo(myGraph); // 调用算法文件中的打印函数验证
    }
    else {
        std::cout << "图创建失败，请检查文件路径和格式！" << std::endl;
    }*/
    static Graph myGraph1;
    static Graph myGraph2;
    static Graph myGraph3;
    static Graph myGraph4;
    const char* filePath1 = "grpData/udg8.grp";
    const char* filePath2 = "grpData/udg115.grp";
    const char* filePath3 = "grpData/dg6.grp";
    const char* filePath4 = "grpData/f14.grp";
    if (CreateGrpFromFile((char*)filePath1, myGraph1)) 
    {
        //PrintGraphInfo(myGraph1); // 调用算法文件中的打印函数验证
    }
    else {
        std::cout << "图创建失败，请检查文件路径和格式！" << std::endl;
    }

    if (CreateGrpFromFile((char*)filePath2, myGraph2))
    {
        //PrintGraphInfo(myGraph2); // 调用算法文件中的打印函数验证
    }
    else {
        std::cout << "图创建失败，请检查文件路径和格式！" << std::endl;
    }

    if (CreateGrpFromFile((char*)filePath3, myGraph3))
    {
        //PrintGraphInfo(myGraph3); // 调用算法文件中的打印函数验证
    }
    else {
        std::cout << "图创建失败，请检查文件路径和格式！" << std::endl;
    }

    if (CreateGrpFromFile((char*)filePath4, myGraph4))
    {
        //PrintGraphInfo(myGraph4); // 调用算法文件中的打印函数验证
    }
    else {
        std::cout << "图创建失败，请检查文件路径和格式！" << std::endl;
    }


    //T2
    std::cout << "判断图是否连通a->c" << std::endl;
    std::cout << "图一：";
    if (ifPass(myGraph1, 'a', 'c'))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;
    std::cout << "图二：";
    if (ifPass(myGraph2, 'a', 'c'))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;
   
    std::cout << "图三：";
    if (ifPass(myGraph3, 'a', 'c'))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;

    std::cout << "判断图是否连通A->C" << std::endl;
    std::cout << "图四：";
    if (ifPass(myGraph4, 'A', 'C'))
        std::cout << "Yes." << std::endl;
    else
        std::cout << "No." << std::endl;



    return 0;
}
