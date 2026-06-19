#define _CRT_SECURE_NO_WARNINGS // 必须放在第一行！解决 VS2022 中 fopen, strtok 的安全报错

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GraphCreate.h"
#include "GraphStruct.h"

// 删除字符串左边空格的辅助函数
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

// 从数据文件创建图
bool CreateGrpFromFile(char fileName[], Graph& G)
{
	FILE* pFile;
	char str[1000];
	char strTemp[10];
	cellType  eWeight;
	GraphKind GrpType;

	pFile = fopen(fileName, "r");
	if (!pFile)
	{
		printf("错误：文件%s打开失败。\n", fileName);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}

	if (strstr(str, "Graph") == NULL)
	{
		printf("错误：打开的文件格式错误！\n");
		fclose(pFile);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}

	if (strstr(str, "UDG")) GrpType = UDG;
	else if (strstr(str, "UDN")) GrpType = UDN;
	else if (strstr(str, "DG")) GrpType = DG;
	else if (strstr(str, "DN")) GrpType = DN;
	else
	{
		printf("错误：读取图的类型标记失败！\n");
		fclose(pFile);
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;
		else break;
	}

	char* token = strtok(str, " ");
	int nNum = 1;
	while (token != NULL)
	{
		G.data[nNum] = *token;
		token = strtok(NULL, " ");
		nNum++;
	}
	nNum--;

	int nRow = 1;
	int nCol = 1;
	if (GrpType == UDG || GrpType == DG)
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = 0;
	}
	else
	{
		for (nRow = 1; nRow <= nNum; nRow++)
			for (nCol = 1; nCol <= nNum; nCol++)
				G.AdjMatrix[nRow][nCol] = INF;
	}

	int edgeNum = 0;
	elementType Nf, Ns;
	while (fgets(str, 1000, pFile) != NULL)
	{
		strLTrim(str);
		if (str[0] == '\n') continue;
		strncpy(strTemp, str, 2);
		if (strstr(strTemp, "//") != NULL) continue;

		char* token = strtok(str, " ");

		if (token == NULL)
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile);
			return false;
		}
		Nf = *token;

		token = strtok(NULL, " ");
		if (token == NULL)
		{
			printf("错误：读取图的边数据失败！\n");
			fclose(pFile);
			return false;
		}

		Ns = *token;

		for (nRow = 1; nRow <= nNum; nRow++)
		{
			if (G.data[nRow] == Nf) break;
		}

		for (nCol = 1; nCol <= nNum; nCol++)
		{
			if (G.data[nCol] == Ns) break;
		}

		if (GrpType == UDN || GrpType == DN)
		{
			token = strtok(NULL, " ");
			if (token == NULL)
			{
				printf("错误：读取图的边数据失败！\n");
				fclose(pFile);
				return false;
			}
			eWeight = atoi(token);
		}

		if (GrpType == UDN || GrpType == DN)
			G.AdjMatrix[nRow][nCol] = eWeight;
		else
			G.AdjMatrix[nRow][nCol] = 1;

		edgeNum++;
	}

	G.VerNum = nNum;
	if (GrpType == UDG || GrpType == UDN)
		G.ArcNum = edgeNum / 2;
	else
		G.ArcNum = edgeNum;

	G.gKind = GrpType;

	fclose(pFile);
	return true;
}

