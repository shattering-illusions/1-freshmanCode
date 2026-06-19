#pragma once

#define INF 65535                  //定义无穷大
#define MaxVerNum  1000            //定义最大顶点个数

typedef char elementType;         //定义图中顶点的数据类型
typedef int eInfoType;            //定义eInfo的数据类型，即权值的数据类型

//枚举图的类型--无向图，无向网，有向图，有向网
typedef enum { UDG, UDN, DG, DN } GraphKind;

//定义边链表的结点结构
typedef struct eNode
{
	int adjVer;           //邻接顶点编号，从1开始
	eInfoType eInfo;      //边的相关信息（如权值）
	struct eNode* next;   //指向边链表中的下一个结点
}EdgeNode;

//定义顶点表的结点结构
typedef struct vNode
{
	elementType data;     //存放图中顶点的数据值
	EdgeNode* firstEdge;  //指向边链表头指针
}VerNode;

//定义图的整体结构
typedef struct GraphAdjLinkList
{
	VerNode VerList[MaxVerNum];
	int VerNum;           //顶点数
	int ArcNum;           //弧（边）数
	GraphKind gKind;      //图的类型
}Graph;
