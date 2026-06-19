#define _CRT_SECURE_NO_WARNINGS // 必须放在第一行

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GraphCreate.h"
#include "GraphStruct.h"

// 删除字符串左边空格
static void strLTrim(char* str)
{
	int i, j;
	int n = 0;
	n = strlen(str) + 1;
	for (i = 0; i < n; i++)
	{
		if (str[i] != ' ')
			break;
	}
	for (j = 0; j < n; j++)
	{
		str[j] = str[i];
		i++;
	}
}

// 1. 从邻接矩阵格式文件创建图
int CreateGrpFromFile1(char fileName[], Graph& G)
{
	// （此处填入你提供的 CreateGrpFromFile1 函数的完整代码，为了简洁我省略重复粘贴）
	// 请将你问题中 CreateGrpFromFile1 的大括号内代码完整复制到这里！
	FILE* pFile;
	char str[1000];
	char strTemp[10];
	char* ss;
	int i = 0, j = 0;
	int edgeNum = 0;
	GraphKind graphType;

	pFile = fopen(fileName, "r");
	if (!pFile) { printf("错误：文件%s打开失败。\n", fileName); return false; }

	ss = fgets(str, 1000, pFile);
	strncpy(strTemp, str, 2);
	while ((ss != NULL) && (strstr(strTemp, "//") != NULL)) { ss = fgets(str, 1000, pFile); strncpy(strTemp, str, 2); }
	if (strstr(str, "Graph") == NULL) { printf("错误：打开的文件格式错误！\n"); fclose(pFile); return false; }

	if (fgets(str, 1000, pFile) == NULL) { printf("错误：读取图的类型标记失败！\n"); fclose(pFile); return false; }
	if (strstr(str, "UDG")) graphType = UDG;
	else if (strstr(str, "UDN")) graphType = UDN;
	else if (strstr(str, "DG")) graphType = DG;
	else if (strstr(str, "DN")) graphType = DN;
	else { printf("错误：读取图的类型标记失败！\n"); fclose(pFile); return false; }

	if (fgets(str, 1000, pFile) == NULL) { printf("错误：读取图的顶点元素失败！\n"); fclose(pFile); return false; }

	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL) { G.VerList[nNum].data = *token; G.VerList[nNum].firstEdge = NULL; token = strtok(NULL, " "); nNum++; }

	int nRow = 1;
	int nCol = 1;
	EdgeNode* eR;
	EdgeNode* p;

	while (fgets(str, 1000, pFile) != NULL)
	{
		eR = NULL; p = NULL; nCol = 1;
		char* token = strtok(str, " ");
		while (token != NULL)
		{
			if (atoi(token) >= 1 && atoi(token) < INF)
			{
				p = new EdgeNode;
				p->adjVer = nCol;
				p->eInfo = atoi(token);
				p->next = NULL;
				if (G.VerList[nRow].firstEdge == NULL) { G.VerList[nRow].firstEdge = p; eR = p; }
				else { eR->next = p; eR = p; }
				edgeNum++;
			}
			token = strtok(NULL, " ");
			nCol++;
		}
		nRow++;
	}

	G.VerNum = nNum;
	if (graphType == UDG || graphType == UDN) G.ArcNum = edgeNum / 2;
	else G.ArcNum = edgeNum;
	G.gKind = graphType;
	fclose(pFile);
	return true;
}

// 2. 从顶点对（边）格式文件创建图
int CreateGraphFromFile(char fileName[], Graph& G)
{
	// （此处填入你提供的 CreateGraphFromFile 函数的完整代码）
	FILE* pFile;
	char str[1000];
	char strTemp[10];
	int i = 0, j = 0;
	int edgeNum = 0;
	eInfoType eWeight;
	GraphKind graphType;

	pFile = fopen(fileName, "r");
	if (!pFile) { printf("错误：文件%s打开失败。\n", fileName); return false; }

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}
	if (strstr(str, "Graph") == NULL) { printf("错误：打开的文件格式错误！\n"); fclose(pFile); return false; }

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}
	if (strstr(str, "UDG")) graphType = UDG;
	else if (strstr(str, "UDN")) graphType = UDN;
	else if (strstr(str, "DG")) graphType = DG;
	else if (strstr(str, "DN")) graphType = DN;
	else { printf("错误：读取图的类型标记失败！\n"); fclose(pFile); return false; }

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}

	char* token = strtok(str, " ");
	int nNum = 0;
	while (token != NULL) { G.VerList[nNum + 1].data = *token; G.VerList[nNum + 1].firstEdge = NULL; token = strtok(NULL, " "); nNum++; }

	int nRow = 1;
	int nCol = 1;
	EdgeNode* eR;
	EdgeNode* p;
	elementType Nf, Ns;

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;

		char* token = strtok(str, " ");
		if (token == NULL) { printf("错误：读取图的边数据失败！\n"); fclose(pFile); return false; }
		Nf = *token;
		token = strtok(NULL, " ");
		if (token == NULL) { printf("错误：读取图的边数据失败！\n"); fclose(pFile); return false; }
		Ns = *token;

		for (nRow = 1;nRow <= nNum;nRow++) { if (G.VerList[nRow].data == Nf) break; }
		for (nCol = 1;nCol <= nNum;nCol++) { if (G.VerList[nCol].data == Ns) break; }

		if (graphType == UDN || graphType == DN)
		{
			token = strtok(NULL, " ");
			if (token == NULL) { printf("错误：读取图的边数据失败！\n"); fclose(pFile); return false; }
			eWeight = atoi(token);
		}

		eR = G.VerList[nRow].firstEdge;
		while (eR != NULL && eR->next != NULL) { eR = eR->next; }

		p = new EdgeNode;
		p->adjVer = nCol;
		if (graphType == UDN || graphType == DN) p->eInfo = eWeight;
		else p->eInfo = 1;
		p->next = NULL;

		if (G.VerList[nRow].firstEdge == NULL) { G.VerList[nRow].firstEdge = p; eR = p; }
		else { eR->next = p; eR = p; }
		edgeNum++;
	}

	G.VerNum = nNum;
	if (graphType == UDG || graphType == UDN) G.ArcNum = edgeNum / 2;
	else G.ArcNum = edgeNum;
	G.gKind = graphType;
	fclose(pFile);
	return true;
}

// 3. 销毁图
void DestroyGraph(Graph& G)
{
	EdgeNode* p, * u;
	int vID;
	for (vID = 1; vID <= G.VerNum; vID++)
	{
		p = G.VerList[vID].firstEdge;
		G.VerList[vID].firstEdge = NULL;
		while (p)
		{
			u = p->next;
			delete(p);
			p = u;
		}
	}
	p = NULL;
	u = NULL;
	G.VerNum = -1;
}
