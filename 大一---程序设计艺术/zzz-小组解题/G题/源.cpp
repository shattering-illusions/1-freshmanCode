#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

// 树状数组 1：单点修改，区间查询（维护需求量 d）
struct BIT_D {
    int n;
    vector<long long> tree;
    void init(int n_) { n = n_; tree.assign(n + 2, 0); }
    void add(int i, long long delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    long long query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
} bit_d;

// 树状数组 2：区间修改，单点查询（维护到根节点的距离）
struct BIT_Dist {
    int n;
    vector<long long> tree;
    void init(int n_) { n = n_; tree.assign(n + 2, 0); }
    void add(int i, long long delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    void add_range(int l, int r, long long delta) {
        if (l > r) return;
        add(l, delta);
        add(r + 1, -delta);
    }
    long long query(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
} bit_dist;

// 原树边结构
struct Edge {
    int to;
    long long w;
};

int n, q;
vector<long long> d;
vector<vector<Edge>> adj;
vector<long long> edge_to_child_weight; // 记录每条边进入子节点时的初始权重

// DFS 预处理相关变量
int timer = 0;
vector<int> pos, sz, depth;
vector<vector<int>> up;

void dfs_init(int u, int p, int dep) {
    pos[u] = ++timer;
    sz[u] = 1;
    depth[u] = dep;
    up[u][0] = p;
    for (int j = 1; j < 20; ++j) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }
    for (const auto& edge : adj[u]) {
        int v = edge.to;
        if (v != p) {
            edge_to_child_weight[v] = edge.w;
            dfs_init(v, u, dep + 1);
            sz[u] += sz[v];
        }
    }
}

// 获取最近公共祖先 LCA
int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int j = 19; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) u = up[u][j];
    }
    if (u == v) return u;
    for (int j = 19; j >= 0; --j) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

// 检查 a 是否是 b 的祖先
bool is_ancestor(int a, int b) {
    return pos[a] <= pos[b] && pos[a] + sz[a] >= pos[b] + sz[b];
}

// 虚树相关变量
vector<vector<int>> v_adj;
vector<int> closest_center;
vector<long long> closest_dist;
vector<int> is_query_center;
vector<long long> ans;

// 辅助更新最邻近服务中心
void update_closest(int u, long long dist_val, int center_id) {
    if (center_id == -1) return;
    if (dist_val < closest_dist[u]) {
        closest_dist[u] = dist_val;
        closest_center[u] = center_id;
    }
    else if (dist_val == closest_dist[u]) {
        if (closest_center[u] == -1 || center_id < closest_center[u]) {
            closest_center[u] = center_id;
        }
    }
}

// 虚树 DP Pass 1：自底向上
void v_dfs1(int u) {
    if (is_query_center[u] != -1) {
        update_closest(u, 0, is_query_center[u]);
    }
    for (int v : v_adj[u]) {
        v_dfs1(v);
        long long edge_w = bit_dist.query(pos[v]) - bit_dist.query(pos[u]);
        update_closest(u, closest_dist[v] + edge_w, closest_center[v]);
    }
}

// 虚树 DP Pass 2：自顶向下
void v_dfs2(int u) {
    for (int v : v_adj[u]) {
        long long edge_w = bit_dist.query(pos[v]) - bit_dist.query(pos[u]);
        update_closest(v, closest_dist[u] + edge_w, closest_center[u]);
        v_dfs2(v);
    }
}

// 判断节点 p 在划分中是否更偏好 cx 
bool prefers_cx(int p, int x, int y, int cx, int cy, long long dist_x, long long dist_y, long long dist_cx, long long dist_cy) {
    long long d_p = bit_dist.query(pos[p]);
    long long total_dist_x = (d_p - dist_x) + dist_cx;
    long long total_dist_y = (dist_y - d_p) + dist_cy;

    if (total_dist_x < total_dist_y) return true;
    if (total_dist_x > total_dist_y) return false;
    return cx < cy; // 距离相等，比较编号
}

int main() {
    // 提升输入输出流性能
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    d.resize(n + 1);
    adj.resize(n + 1);
    edge_to_child_weight.resize(n + 1);
    pos.resize(n + 1);
    sz.resize(n + 1);
    depth.resize(n + 1);
    up.assign(n + 1, vector<int>(20, 0));

    bit_d.init(n);
    bit_dist.init(n);

    for (int i = 1; i <= n; ++i) cin >> d[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }
    // 预处理 DFS 序及倍增表
    dfs_init(1, 0, 1);

    // 树状数组赋初值
    for (int i = 1; i <= n; ++i) {
        bit_d.add(pos[i], d[i]);
        if (i != 1) {
            bit_dist.add_range(pos[i], pos[i] + sz[i] - 1, edge_to_child_weight[i]);
        }
    }

    // 虚树辅助辅助数组
    v_adj.resize(n + 1);
    closest_center.assign(n + 1, -1);
    closest_dist.assign(n + 1, INF);
    is_query_center.assign(n + 1, -1);
    ans.assign(n + 1, 0);

    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u;
            long long val;
            cin >> u >> val;
            long long delta = val - d[u];
            d[u] = val;
            bit_d.add(pos[u], delta);
        }
        else if (op == 2) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            int child = (depth[u] > depth[v]) ? u : v;
            long long delta = w - edge_to_child_weight[child];
            edge_to_child_weight[child] = w;
            bit_dist.add_range(pos[child], pos[child] + sz[child] - 1, delta);
        }
        else if (op == 3) {
            int k;
            cin >> k;
            vector<int> centers(k);
            for (int i = 0; i < k; ++i) {
                cin >> centers[i];
                is_query_center[centers[i]] = centers[i];
                ans[centers[i]] = 0; // 清空历史答案
            }

            // 建立虚树：1. 按 DFS 序排序
            vector<int> v_nodes = centers;
            sort(v_nodes.begin(), v_nodes.end(), [](int a, int b) { return pos[a] < pos[b]; });

            // 2. 加入相邻节点的 LCA
            int m = v_nodes.size();
            for (int i = 0; i < m - 1; ++i) {
                v_nodes.push_back(get_lca(v_nodes[i], v_nodes[i + 1]));
            }
            sort(v_nodes.begin(), v_nodes.end(), [](int a, int b) { return pos[a] < pos[b]; });
            v_nodes.erase(unique(v_nodes.begin(), v_nodes.end()), v_nodes.end());

            // 3. 用栈连边构建虚树
            vector<int> stk;
            for (int u : v_nodes) {
                v_adj[u].clear();
                closest_center[u] = -1;
                closest_dist[u] = INF;

                while (!stk.empty() && !is_ancestor(stk.back(), u)) {
                    stk.pop_back();
                }
                if (!stk.empty()) {
                    v_adj[stk.back()].push_back(u);
                }
                stk.push_back(u);
            }

            int v_root = v_nodes[0];

            // 运行两遍 DP，决定虚树每个顶点的归属
            v_dfs1(v_root);
            v_dfs2(v_root);

            // 差分统计各个中心的辐射总量
            ans[closest_center[v_root]] += bit_d.query_range(pos[1], pos[1] + sz[1] - 1);

            for (int x : v_nodes) {
                for (int y : v_adj[x]) {
                    int cx = closest_center[x];
                    int cy = closest_center[y];

                    // 倍增查找划分长链归属的分界点 nxt_z
                    int nxt_z = y;
                    int curr = y;
                    long long dist_x = bit_dist.query(pos[x]);
                    long long dist_y = bit_dist.query(pos[y]);
                    long long dist_cx = closest_dist[x];
                    long long dist_cy = closest_dist[y];

                    for (int j = 13; j >= 0; --j) {
                        int target = up[curr][j];
                        if (target != 0 && depth[target] > depth[x]) {
                            if (!prefers_cx(target, x, y, cx, cy, dist_x, dist_y, dist_cx, dist_cy)) {
                                nxt_z = target;
                                curr = target;
                            }
                        }
                    }

                    long long subtree_sum = bit_d.query_range(pos[nxt_z], pos[nxt_z] + sz[nxt_z] - 1);
                    ans[cx] -= subtree_sum;
                    ans[cy] += subtree_sum;
                }
            }

            // 按输入顺序打印答案
            for (int i = 0; i < k; ++i) {
                cout << ans[centers[i]] << (i == k - 1 ? "" : " ");
                is_query_center[centers[i]] = -1; // 恢复辅助状态
            }
            cout << "\n";
        }
    }

    return 0;
}