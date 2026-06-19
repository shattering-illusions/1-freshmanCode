#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

// 定义二维点/向量
struct Point {
    double x, y;
};

// 计算叉积 (B - A) x (C - A)
// 返回正数表示 C 在 AB 左侧，负数表示在右侧，0 表示共线
double cross_product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// 检查点 P 是否在线段 AB 上（包括端点）
bool on_segment(Point P, Point A, Point B) {
    return abs(cross_product(A, B, P)) < EPS &&
        P.x >= min(A.x, B.x) - EPS && P.x <= max(A.x, B.x) + EPS &&
        P.y >= min(A.y, B.y) - EPS && P.y <= max(A.y, B.y) + EPS;
}

// 检查线段 AB 和 CD 是否有任何交点（包括端点）
bool segments_intersect(Point A, Point B, Point C, Point D) {
    double c1 = cross_product(A, B, C);
    double c2 = cross_product(A, B, D);
    double c3 = cross_product(C, D, A);
    double c4 = cross_product(C, D, B);

    // 规范相交（跨立试验成功）
    if (((c1 > EPS && c2 < -EPS) || (c1 < -EPS && c2 > EPS)) &&
        ((c3 > EPS && c4 < -EPS) || (c3 < -EPS && c4 > EPS))) {
        return true;
    }

    // 端点在线段上的边界情况
    if (abs(c1) < EPS && on_segment(C, A, B)) return true;
    if (abs(c2) < EPS && on_segment(D, A, B)) return true;
    if (abs(c3) < EPS && on_segment(A, C, D)) return true;
    if (abs(c4) < EPS && on_segment(B, C, D)) return true;

    return false;
}

void solve() {
    int n;
    int case_num = 1;

    while (cin >> n && n != 0) {
        // 每两组测试数据之间打印一个空行
        if (case_num > 1) {
            cout << "\n";
        }

        vector<Point> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }

        cout << "Figure " << case_num << ": ";
        case_num++;

        // 1. 点数不足
        if (n < 3) {
            cout << "Impossible\n";
            continue;
        }

        // 2. 计算面积
        double area = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            area += p[i].x * p[j].y - p[j].x * p[i].y;
        }
        area = abs(area) / 2.0;

        if (area < EPS) {
            cout << "Impossible\n";
            continue;
        }

        // 3. 检查边是否自交
        bool is_possible = true;
        for (int i = 0; i < n && is_possible; i++) {
            for (int j = i + 1; j < n; j++) {
                int next_i = (i + 1) % n;
                int next_j = (j + 1) % n;

                // 判断是否为相邻边
                bool is_adjacent = (next_i == j || next_j == i);

                if (is_adjacent) {
                    // 如果是相邻边，它们共享一个顶点。
                    // 此时只需检查第三个顶点是否落在了另一条边上（导致重叠/退化）
                    Point shared = (next_i == j) ? p[j] : p[i];
                    Point other1 = (next_i == j) ? p[i] : p[next_j];
                    Point other2 = (next_i == j) ? p[next_j] : p[next_i];

                    if (on_segment(other1, shared, other2) || on_segment(other2, shared, other1)) {
                        is_possible = false;
                        break;
                    }
                }
                else {
                    // 如果是非相邻边，绝对不能有任何交点
                    if (segments_intersect(p[i], p[next_i], p[j], p[next_j])) {
                        is_possible = false;
                        break;
                    }
                }
            }
        }

        if (is_possible) {
            cout << fixed << setprecision(2) << area << "\n";
        }
        else {
            cout << "Impossible\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
