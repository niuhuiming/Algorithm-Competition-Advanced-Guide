#include <iostream>
using namespace std;
const int N = 100010, INF = 1e8;
// 1.插入 2.删除 3.找前驱/后继 4.找最大/最小 5.求某个值的排名
// 6.求排名为rk的数 7.找比某个数小的最大值 8.找比某个数大的最小值
struct Node {
    int l, r;
    int key, val;  // val是随机值
    // cnt记录该结点的副本数
    // size记录以该节点为根的子树中所有节点的副本数之和
    int cnt, size;
} tr[N];
int root, idx;

void pushup(int p) {  // 用p的两个儿子算p的信息
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}
int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;  // 创建的是叶节点，所以cnt, size都是1
    return idx;
}
void build() {  // 加两个哨兵
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
}
// root是变化的，要传引用，判断左右旋画图
void zig(int& p) {  // 右旋
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}
void zag(int& p) {  // 左旋
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l);
    pushup(p);
}
// 涉及到左旋右旋，要加引用
void insert(int& p, int key) {  // 插入数字key
    if (p == 0) p = get_node(key);
    else if (tr[p].key == key) tr[p].cnt++;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    } else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}
// 涉及到左旋右旋，要加引用
void remove(int& p, int key) {  // 删除数字key
    if (p == 0) return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {  // 不是叶子节点
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);  // 旋转到了右边 ，在右子树删除
            } else {
                zag(p);
                remove(tr[p].l, key);  // 旋转到了左边 ，在左子树删除
            }
        } else p = 0;  // 是叶子节点
    } else if (tr[p].key > key) remove(tr[p].l, key);
    else remove(tr[p].r, key);
    pushup(p);
}
// get_rank_by_key(root, x) - 1;注意build()时加入一个-INF
int get_rank_by_key(int p, int key) {  // 返回key的排名
    if (!p) return 0;                  // 不存在key返回0
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}
// get_key_by_rank(root, x + 1); 注意build()时加入一个-INF
int get_key_by_rank(int p, int rank) {  // 返回排名为rank的数
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}
int get_prev(int p, int key) {  // 返回小于key的最大数
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}
int get_next(int p, int key) {  // 返回大于key的最小数
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}
int main() {
    build();
    int n;
    scanf("%d", &n);
    while (n--) {
        int opt, x;
        scanf("%d%d", &opt, &x);
        if (opt == 1) insert(root, x);
        else if (opt == 2) remove(root, x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(root, x) - 1);
        else if (opt == 4) printf("%d\n", get_key_by_rank(root, x + 1));
        else if (opt == 5) printf("%d\n", get_prev(root, x));
        else printf("%d\n", get_next(root, x));
    }
    return 0;
}
