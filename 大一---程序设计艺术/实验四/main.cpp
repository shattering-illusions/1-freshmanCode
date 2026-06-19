#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 求两个字符串的最长公共子序列
string LCS(const string& X, const string& Y) {
    int m = X.size();
    int n = Y.size();

    // dp[i][j] 表示 X[0..i-1] 与 Y[0..j-1] 的 LCS 长度
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 填 DP 表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 从 dp[m][n] 回溯构造 LCS 字符串
    int len = dp[m][n];
    string result(len, '\0'); // 预分配长度，从后向前填充
    int i = m, j = n;
    int idx = len - 1;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            result[idx--] = X[i - 1];
            i--; j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return result;
}

// ========== 问题2：编辑距离（最小编辑次数 + 输出变换步骤） ==========

// 操作类型
enum class EditOp { MATCH, INSERT, DELETE, REPLACE };

// 计算编辑距离并输出变换步骤，返回最少操作次数
int editDistance(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();

    // dp[i][j] = 将 a[0..i-1] 变为 b[0..j-1] 的最少操作数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 边界：将空串变为 b[0..j-1] 需要 j 次插入
    for (int j = 0; j <= n; j++) dp[0][j] = j;
    // 边界：将 a[0..i-1] 变为空串需要 i 次删除
    for (int i = 0; i <= m; i++) dp[i][0] = i;

    // 填 DP 表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // 字符相同，无需操作
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],      // 删除 a[i-1]
                    dp[i][j - 1],      // 插入 b[j-1]
                    dp[i - 1][j - 1]   // 替换 a[i-1] → b[j-1]
                });
            }
        }
    }

    // ---------- 回溯构造步骤 ----------
    struct Step {
        EditOp op;
        char from;   // 被删除/替换的字符（INSERT 时无意义）
        char to;     // 插入/替换后的字符（DELETE 时无意义）
    };
    vector<Step> steps;

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && a[i - 1] == b[j - 1]) {
            // 字符相同 → 匹配（保持）
            steps.push_back({EditOp::MATCH, a[i - 1], a[i - 1]});
            i--; j--;
        }
        else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            // 替换
            steps.push_back({EditOp::REPLACE, a[i - 1], b[j - 1]});
            i--; j--;
        }
        else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            // 删除 a[i-1]
            steps.push_back({EditOp::DELETE, a[i - 1], '\0'});
            i--;
        }
        else {
            // 插入 b[j-1]
            steps.push_back({EditOp::INSERT, '\0', b[j - 1]});
            j--;
        }
    }

    // 步骤是逆序收集的，翻转后正序输出
    reverse(steps.begin(), steps.end());

    // ---------- 正向模拟，输出每一步 ----------
    string cur = a;  // 当前字符串状态
    int pos = 0;      // 当前在原始串 a 中的逻辑位置
    int stepNum = 0;

    cout << "初始: \"" << cur << "\"" << endl;

    for (const auto& s : steps) {
        stepNum++;
        switch (s.op) {
        case EditOp::MATCH:
            cout << "步骤" << stepNum << " (匹配):   '" << s.from
                 << "' 相同，保持不变 → \"" << cur << "\"" << endl;
            pos++;
            break;
        case EditOp::REPLACE:
            cur[pos] = s.to;
            cout << "步骤" << stepNum << " (替换):   将 '" << s.from
                 << "' 替换为 '" << s.to << "' → \"" << cur << "\"" << endl;
            pos++;
            break;
        case EditOp::DELETE:
            cur.erase(pos, 1);
            cout << "步骤" << stepNum << " (删除):   删除 '" << s.from
                 << "' → \"" << cur << "\"" << endl;
            // pos 不变（下一个字符移到当前位置）
            break;
        case EditOp::INSERT:
            cur.insert(pos, 1, s.to);
            cout << "步骤" << stepNum << " (插入):   在位置" << (pos + 1)
                 << "插入 '" << s.to << "' → \"" << cur << "\"" << endl;
            pos++;
            break;
        }
    }

    return dp[m][n];
}

// ========== 问题3：最大子矩阵和  ==========

/*
 * 暴力法 O(n⁶)：枚举所有子矩阵 (O(n⁴))，每个求和 O(n²)
 *           → 100×100 矩阵需要约 10¹² 次操作，不可行。
 *
 * DP 优化 O(n³)（2D Kadane）：
 *   固定上下行 top/bottom，将行区间压缩为一维数组 colSum，
 *   然后对 colSum 跑 Kadane（最大子数组和，O(n)）。
 *   两层行枚举 O(n²) × Kadane O(n) = O(n³)。
 *   100×100 仅约 10⁶ 次操作，瞬间完成。
 */
int maxSubmatrixSum(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSum = matrix[0][0];  // 初始化为第一个元素，处理全负数

    // 枚举上边界
    for (int top = 0; top < rows; top++) {
        vector<int> colSum(cols, 0);  // 压缩后的列和

        // 枚举下边界（边扩展边累加）
        for (int bottom = top; bottom < rows; bottom++) {
            // 将第 bottom 行累加到 colSum
            for (int c = 0; c < cols; c++) {
                colSum[c] += matrix[bottom][c];
            }

            // ---------- Kadane 一维最大子数组和 ----------
            int cur = colSum[0];
            int best = cur;
            for (int c = 1; c < cols; c++) {
                cur = max(colSum[c], cur + colSum[c]);
                best = max(best, cur);
            }
            maxSum = max(maxSum, best);
        }
    }

    return maxSum;
}

// 重载：同时返回构成最大和的子矩阵边界 [top, bottom, left, right]
int maxSubmatrixSum(const vector<vector<int>>& matrix,
                    int& outTop, int& outBottom, int& outLeft, int& outRight) {
    if (matrix.empty() || matrix[0].empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSum = matrix[0][0];
    outTop = outBottom = outLeft = outRight = 0;

    for (int top = 0; top < rows; top++) {
        vector<int> colSum(cols, 0);

        for (int bottom = top; bottom < rows; bottom++) {
            for (int c = 0; c < cols; c++) {
                colSum[c] += matrix[bottom][c];
            }

            // Kadane，同时追踪左右边界
            int cur = colSum[0];
            int best = cur;
            int left = 0, bestLeft = 0, bestRight = 0;

            for (int c = 1; c < cols; c++) {
                if (colSum[c] > cur + colSum[c]) {
                    cur = colSum[c];
                    left = c;
                } else {
                    cur = cur + colSum[c];
                }
                if (cur > best) {
                    best = cur;
                    bestLeft = left;
                    bestRight = c;
                }
            }

            if (best > maxSum) {
                maxSum = best;
                outTop = top;
                outBottom = bottom;
                outLeft = bestLeft;
                outRight = bestRight;
            }
        }
    }

    return maxSum;
}

// 打印矩阵
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int x : row) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

int main() {
    // ==================== 问题1：最长公共子序列 (LCS) ====================
    {
        struct TestCase {
            string X;
            string Y;
            string expected;
        };

        TestCase tests[] = {
            { "pear",  "peach",  "pea"   },
            { "ABCBDAB", "BDCABA", "BDAB" },
            { "abc",   "def",    ""      },
            { "hello", "hello",  "hello" },
            { "",      "abc",    ""      },
            { "abc",   "",       ""      },
            { "ABCDEFG", "ACEG", "ACEG" },
        };

        int numTests = sizeof(tests) / sizeof(tests[0]);
        int passed = 0;

        cout << "========================================" << endl;
        cout << "  问题1：最长公共子序列 (LCS) 测试" << endl;
        cout << "========================================" << endl << endl;

        for (int t = 0; t < numTests; t++) {
            string result = LCS(tests[t].X, tests[t].Y);
            bool ok = (result == tests[t].expected);

            cout << "测试 " << (t + 1) << ": "
                 << "X=\"" << tests[t].X << "\", "
                 << "Y=\"" << tests[t].Y << "\""
                 << endl;
            cout << "  结果: \"" << result << "\"";
            if (!tests[t].expected.empty() || !result.empty()) {
                cout << "  期望: \"" << tests[t].expected << "\"";
            }
            cout << "  [" << (ok ? "通过" : "失败") << "]" << endl;

            if (ok) passed++;
        }

        cout << endl << "通过 " << passed << "/" << numTests << " 组测试" << endl;
    }

    cout << endl << endl;

    // ==================== 问题2：编辑距离（最小编辑次数 + 变换步骤） ====================
    {
        cout << "========================================" << endl;
        cout << "  问题2：编辑距离 + 变换步骤" << endl;
        cout << "========================================" << endl << endl;

        cout << "将 \"" << "pear" << "\" 变为 \"" << "peach" << "\"" << endl << endl;

        int dist = editDistance("pear", "peach");

        cout << endl << "编辑距离 = " << dist << " (期望 2)";
        cout << "  [" << (dist == 2 ? "通过" : "失败") << "]" << endl;
    }

    cout << endl << endl;

    // ==================== 问题3：最大子矩阵和 ====================
    {
        cout << "========================================" << endl;
        cout << "  问题3：最大子矩阵和 " << endl;
        cout << "========================================" << endl << endl;

        vector<vector<int>> mat = {
            { 0, -2, -7,  0},
            { 9,  2, -6,  2},
            {-4,  1, -4,  1},
            {-1,  8,  0, -2}
        };
        cout << "矩阵:" << endl;
        printMatrix(mat);

        int t, b, l, r;
        int result = maxSubmatrixSum(mat, t, b, l, r);
        cout << "最大子矩阵和 = " << result
             << "  子矩阵: 行[" << (t+1) << "," << (b+1)
             << "]  列[" << (l+1) << "," << (r+1) << "]" << endl;
        cout << "期望: 15  [" << (result == 15 ? "通过" : "失败") << "]" << endl;
    }

    return 0;
}
