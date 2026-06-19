#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF = 1e9;

struct Point 
{
    double x, y;
};

struct Wall 
{
    double x;
    double y1, y2, y3, y4;
};

// 检查线段 p1p2 是否被墙体阻挡
bool is_blocked(Point p1, Point p2, const vector<Wall>& walls) 
{
    double xa = p1.x, ya = p1.y;
    double xb = p2.x, yb = p2.y;
    if (xa > xb) 
    {
        swap(xa, xb);
        swap(ya, yb);
    }
    for (const auto& w : walls) 
    {
        if (w.x > xa && w.x < xb) 
        {
            // 计算交点 y
            double wy = ya + (yb - ya) * (w.x - xa) / (xb - xa);
            // 判断是否在两个门洞外
            if (!((w.y1 <= wy && wy <= w.y2) || (w.y3 <= wy && wy <= w.y4))) 
            {
                return true; // 被实体墙阻挡
            }
        }
    }
    return false;
}

double get_dist(Point p1, Point p2) 
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() 
{
    int n;
    // 读入墙的个数，输入 -1 时结束
    while (cin >> n && n != -1) 
    {
        vector<Wall> walls(n);
        vector<Point> points;

        // 压入起点 (0, 5)
        points.push_back({ 0.0, 5.0 });

        for (int i = 0; i < n; ++i) 
        {
            cin >> walls[i].x >> walls[i].y1 >> walls[i].y2 >> walls[i].y3 >> walls[i].y4;
            points.push_back({ walls[i].x, walls[i].y1 });
            points.push_back({ walls[i].x, walls[i].y2 });
            points.push_back({ walls[i].x, walls[i].y3 });
            points.push_back({ walls[i].x, walls[i].y4 });
        }

        // 压入终点 (10, 5)
        points.push_back({ 10.0, 5.0 });

        int n_pts = points.size();
        vector<vector<double>> adj(n_pts, vector<double>(n_pts, INF));

        // 建图
        for (int i = 0; i < n_pts; ++i) 
        {
            for (int j = i; j < n_pts; ++j) 
            {
                if (i == j) {
                    adj[i][j] = 0;
                }
                else if (!is_blocked(points[i], points[j], walls)) 
                {
                    double d = get_dist(points[i], points[j]);
                    adj[i][j] = adj[j][i] = d;
                }
            }
        }

        // Dijkstra 算法
        vector<double> dist(n_pts, INF);
        vector<bool> visited(n_pts, false);
        dist[0] = 0;

        for (int k = 0; k < n_pts; ++k) 
        {
            int u = -1;
            double min_d = INF;
            for (int i = 0; i < n_pts; ++i) 
            {
                if (!visited[i] && dist[i] < min_d) 
                {
                    min_d = dist[i];
                    u = i;
                }
            }
            if (u == -1) break;
            visited[u] = true;
            for (int v = 0; v < n_pts; ++v) 
            {
                if (dist[u] + adj[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        // 输出结果，保留两位小数
        cout << fixed << setprecision(2) << dist[n_pts - 1] << endl;
    }
    return 0;
}
