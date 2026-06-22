#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 缓存节点结构体
struct CacheNode {
    list<long long>::iterator it; // 指向 LRU 链表中的位置
    long long value;              // 当前缓存的值
    bool dirty;                   // 脏标记（是否被修改且未写回）
};

int main() {
    // 提升输入输出效率，防止大数据量时超时
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long C;
    if (!(cin >> C)) return 0;

    list<long long> lru_list;                       // 维护新鲜度：前端为 MRU，后端为 LRU
    unordered_map<long long, CacheNode> cache_map;  // 缓存哈希表
    unordered_map<long long, long long> main_memory;// 模拟主存（记录已被写回的数据）

    string token;
    // 健壮的 Token 扫描循环，自动忽略各种空格和单独的分号
    while (cin >> token) {
        if (token == "READ") {
            string key_str;
            cin >> key_str;
            // 剥离末尾可能连带的分号，如 "1;" -> "1"
            if (!key_str.empty() && key_str.back() == ';') {
                key_str.pop_back();
            }
            long long key = stoll(key_str);

            if (cache_map.count(key)) {
                // 1. 读命中：移动到链表最前端(MRU)
                CacheNode& node = cache_map[key];
                lru_list.erase(node.it);
                lru_list.push_front(key);
                node.it = lru_list.begin();

                cout << "READ " << key << ": Hit, value = " << node.value << "\n";
            }
            else {
                // 2. 读缺失：从主存加载，若主存未记录则默认为 0
                long long v = main_memory.count(key) ? main_memory[key] : 0;
                cout << "READ " << key << ": Miss, loaded, value = " << v << "\n";

                if (C > 0) {
                    // 如果缓存满了，淘汰尾部的 LRU 节点
                    if (cache_map.size() == C) {
                        long long lru_key = lru_list.back();
                        lru_list.pop_back();
                        if (cache_map[lru_key].dirty) {
                            main_memory[lru_key] = cache_map[lru_key].value; // 触发写回
                        }
                        cache_map.erase(lru_key);
                    }
                    // 放入缓存前端
                    lru_list.push_front(key);
                    cache_map[key] = { lru_list.begin(), v, false };
                }
            }
        }
        else if (token == "WRITE") {
            string key_str, val_str;
            cin >> key_str >> val_str;
            // 剥离末尾可能连带的分号，如 "20;" -> "20"
            if (!val_str.empty() && val_str.back() == ';') {
                val_str.pop_back();
            }
            long long key = stoll(key_str);
            long long value = stoll(val_str);

            if (cache_map.count(key)) {
                // 3. 写命中：更新值、置脏、移到前端
                CacheNode& node = cache_map[key];
                lru_list.erase(node.it);
                lru_list.push_front(key);
                node.it = lru_list.begin();
                node.value = value;
                node.dirty = true;

                cout << "WRITE " << key << " " << value << ": Hit, updated\n";
            }
            else {
                // 4. 写缺失
                cout << "WRITE " << key << " " << value << ": Miss, loaded and updated\n";

                if (C > 0) {
                    if (cache_map.size() == C) {
                        long long lru_key = lru_list.back();
                        lru_list.pop_back();
                        if (cache_map[lru_key].dirty) {
                            main_memory[lru_key] = cache_map[lru_key].value;
                        }
                        cache_map.erase(lru_key);
                    }
                    lru_list.push_front(key);
                    cache_map[key] = { lru_list.begin(), value, true }; // 新写入的数据是脏数据
                }
                else {
                    // 如果容量 C = 0，直接写回主存
                    main_memory[key] = value;
                }
            }
        }
    }

    // 打印最终缓存状态
    cout << "\n";
    if (lru_list.empty()) {
        cout << "Cache is empty.\n";
    }
    else {
        cout << "Cache state (MRU -> LRU):\n";
        for (long long key : lru_list) {
            cout << key << " : " << cache_map[key].value << "\n";
        }
    }

    return 0;
}