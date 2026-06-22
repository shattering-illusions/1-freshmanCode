#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用一个足够大的数代表正无穷大，防止加法溢出
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

// 边的结构体定义
struct Edge {
    int to;  // 目标节点
    int w;   // 原始耗时
    int c;   // 优化后的耗时
};

int main() {
    // 显著优化 C++ 标准输入输出流的性能，防止因 I/O 导致超时
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, K;
    if (!(cin >> n >> m >> K)) return 0;

    // 使用邻接表存储有向图
    // 题目保证对于所有有向边 (u, v) 均满足 u < v
    // 顶点 1 到 n 已经是一个天然的拓扑序列，可以直接按顺序递推
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        adj[u].push_back({ v, w, c });
    }

    // dp[i][j] 表示到达节点 i 且使用了 j 次优局的最小总耗时
    // 大小为 (n + 1) x (K + 1)，初始化为无穷大 INF
    vector<vector<long long>> dp(n + 1, vector<long long>(K + 1, INF));

    // 起点初始化：处于起点 1 且未使用任何优化时，耗时为 0
    dp[1][0] = 0;

    // 按照天然的拓扑序（从 1 到 n - 1）依次向下游转移状态
    for (int u = 1; u < n; ++u) {
        for (int j = 0; j <= K; ++j) {
            // 如果当前状态不可达，则无法从该状态向下扩展，直接跳过
            if (dp[u][j] == INF) continue;

            // 遍历节点 u 的所有出边
            for (const auto& edge : adj[u]) {
                int v = edge.to;
                int w = edge.w;
                int c = edge.c;

                // 决策 1：不优化当前这条边，保持原耗时 w
                if (dp[u][j] + w < dp[v][j]) {
                    dp[v][j] = dp[u][j] + w;
                }

                // 决策 2：优化当前这条边，使耗时降为 c（前提是当前累计优化次数 j < K）
                if (j < K) {
                    if (dp[u][j] + c < dp[v][j + 1]) {
                        dp[v][j + 1] = dp[u][j] + c;
                    }
                }
            }
        }
    }

    // 在到达终点 n 的所有合法状态（使用 0 到 K 次优化）中找寻最小值
    long long ans = INF;
    for (int j = 0; j <= K; ++j) {
        ans = min(ans, dp[n][j]);
    }

    // 输出最终答案
    cout << ans << "\n";

    return 0;
}
