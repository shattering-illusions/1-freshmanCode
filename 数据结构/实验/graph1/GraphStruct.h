#pragma once  // 防止头文件重复包含

#define INF 65535           // 定义无穷大
#define MaxVerNum  1000     // 定义最大顶点个数

typedef char elementType;   // 顶点数据类型
typedef int cellType;       // 邻接矩阵元素数据类型

// 枚举图的类型
typedef enum { UDG, UDN, DG, DN } GraphKind;

// 邻接矩阵存储结构
typedef struct GraphAdjMatrix
{
    elementType data[MaxVerNum];              // 顶点数组
    cellType AdjMatrix[MaxVerNum][MaxVerNum]; // 邻接矩阵
    int VerNum;       // 顶点数
    int ArcNum;       // 弧（边）数
    GraphKind gKind;  // 图的类型
} Graph;


