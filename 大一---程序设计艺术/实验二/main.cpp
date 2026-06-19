#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;
// =========================================================================
// 1. 八皇后问题 相关定义与实现

vector<vector<int>> solveEightQueens()
{
    vector<vector<int>> solutions;
    vector<int> board(8, -1);

    std::function<void(int)> backtrack = [&](int row)
        {
            if (row == 8)
            {
                solutions.push_back(board);
                return;
            }
            for (int col = 0; col < 8; ++col)
            {
                bool conflict = false;
                for (int prev = 0; prev < row; ++prev)
                {
                    if (board[prev] == col ||
                        abs(board[prev] - col) == abs(prev - row))
                    {
                        conflict = true;
                        break;
                    }
                }
                if (!conflict)
                {
                    board[row] = col;
                    backtrack(row + 1);
                    board[row] = -1;
                }
            }
        };

    backtrack(0);
    return solutions;
}
//输出所有解的情况
void printBoard(const vector<int>& board, int index) 
{
    cout << "解#" << index << ":" << endl;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) 
        {
            if (board[row] == col)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
// =========================================================================
// 3. 双水壶问题 相关定义与实现
// 用于记录路径的结构体
struct StateInfo 
{
    pair<int, int> parent; // 上一个状态
    string action;         // 导致该状态的操作描述
};

// 求最大公约数
int getGCD(int a, int b) 
{
    while (b) 
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// 水壶问题核心求解函数
void solveWaterJug(int A, int B, int L) 
{
    // 边界条件判断
    if (L > max(A, B) || (L % getGCD(A, B) != 0)) 
    {
        cout << "No Solution" << endl;
        return;
    }

    if (L == 0) 
    {
        cout << "Initial State: (0, 0)" << endl;
        return;
    }

    // BFS 队列，存储当前水壶状态 (当前A水量, 当前B水量)
    queue<pair<int, int>> q;
    // 访问集合，防止死循环
    set<pair<int, int>> visited;
    // 路径映射：当前状态 -> 它的父状态及操作
    map<pair<int, int>, StateInfo> path;

    pair<int, int> start = { 0, 0 };
    q.push(start);
    visited.insert(start);

    bool found = false;
    pair<int, int> end_state;

    while (!q.empty()) 
    {
        pair<int, int> curr = q.front();
        q.pop();

        int ca = curr.first;
        int cb = curr.second;

        // 检测是否达到目标
        if (ca == L || cb == L) 
        {
            found = true;
            end_state = curr;
            break;
        }

        // 存储 6 种可能的下一个状态
        vector<pair<pair<int, int>, string>> transitions;

        transitions.push_back({ {A, cb}, "Fill Jug A" });
        transitions.push_back({ {ca, B}, "Fill Jug B" });
        transitions.push_back({ {0, cb}, "Empty Jug A" });
        transitions.push_back({ {ca, 0}, "Empty Jug B" });

        int pourToB = min(ca, B - cb);
        transitions.push_back({ {ca - pourToB, cb + pourToB}, "Pour Jug A into Jug B" });

        int pourToA = min(cb, A - ca);
        transitions.push_back({ {ca + pourToA, cb - pourToA}, "Pour Jug B into Jug A" });

        // 遍历并状态转移
        for (const auto& t : transitions) 
        {
            pair<int, int> next_state = t.first;
            string act = t.second;

            if (visited.find(next_state) == visited.end()) 
            {
                visited.insert(next_state);
                path[next_state] = { curr, act };
                q.push(next_state);
            }
        }
    }

    // 输出水壶问题结果
    if (!found) 
    {
        cout << "No Solution" << endl;
    }
    else 
    {
        vector<string> steps;
        pair<int, int> curr = end_state;

        while (curr != start) 
        {
            StateInfo info = path[curr];
            string step_msg = info.action + " -> Current State: (" +
                to_string(curr.first) + ", " + to_string(curr.second) + ")";
            steps.push_back(step_msg);
            curr = info.parent;
        }

        reverse(steps.begin(), steps.end());

        cout << "Initial State: (0, 0)" << endl;
        for (const auto& step : steps) 
        {
            cout << step << endl;
        }
    }
}

// =========================================================================
// 2. 骑士游历问题 相关定义与实现
const int N = 8;
// 骑士（马）的 8 种合法移动方向
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

// 辅助结构体：记录下一个位置及其后续出位数
struct Cell 
{
    int x, y;
    int degree;
};
// 比较函数：用于将出位数少的格子排在前面
bool compareCells(const Cell& a, const Cell& b) 
{
    return a.degree < b.degree;
}

// 检查坐标 (x, y) 是否在棋盘内且未被访问过
bool isValid(int x, int y, const vector<vector<int>>& board) 
{
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == 0);
}

// 计算坐标 (x, y) 的后续可选出位数
int getDegree(int x, int y, const vector<vector<int>>& board) 
{
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (isValid(x + dx[i], y + dy[i], board)) 
        {
            count++;
        }
    }
    return count;
}

// DFS 回溯核心函数
bool knightTourDFS(int x, int y, int moveCount, vector<vector<int>>& board) 
{
    board[x][y] = moveCount;

    if (moveCount == N * N) {
        return true;
    }

    vector<Cell> nextMoves;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, board)) {
            Cell cell;
            cell.x = nx;
            cell.y = ny;
            cell.degree = getDegree(nx, ny, board);
            nextMoves.push_back(cell);
        }
    }

    // 运用 Warnsdorff 规则排序
    sort(nextMoves.begin(), nextMoves.end(), compareCells);

    for (const auto& next : nextMoves) {
        if (knightTourDFS(next.x, next.y, moveCount + 1, board)) {
            return true;
        }
    }

    board[x][y] = 0;
    return false;
}

// 骑士游历核心求解入口函数
void solveKnightsTour(int startX, int startY) {
    if (startX < 0 || startX >= N || startY < 0 || startY >= N) {
        cout << "No Solution" << endl;
        return;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (knightTourDFS(startX, startY, 1, board)) {
        cout << "Knight's Tour Path (Numbers 1 to 64 represent the steps):" << endl;
        for (int i = 0; i < N; ++i) 
        {
            for (int j = 0; j < N; ++j) 
            {
                cout << setw(3) << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No Solution" << endl;
    }
}
// 主函数 
int main() 
{
    vector<vector<int>> solutions = solveEightQueens();
    cout << "=== 测试 1：八皇后问题演示 ===" << endl;
    cout << "有" << solutions.size() << " 个" << endl;

    cout << "=== 测试 2：骑士游历问题演示 ===" << endl;
    int startX = 0, startY = 0;
    cout << "Starting Position: (" << startX << ", " << startY << ")" << endl;
    solveKnightsTour(startX, startY);

    cout << "=== 测试 3：双水壶问题演示 ===" << endl;
    int A = 3, B = 5, L = 4;
    cout << "Target: Get " << L << "L using " << A << "L and " << B << "L jugs." << endl;
    solveWaterJug(A, B, L);
    cout << "\n" << string(50, '-') << "\n" << endl;


    return 0;
}


