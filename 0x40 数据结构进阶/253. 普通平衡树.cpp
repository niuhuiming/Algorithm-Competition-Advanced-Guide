#include <iostream>
using namespace std;
const int N = 100010, INF = 1e8;
// 1.���� 2.ɾ�� 3.��ǰ��/��� 4.�����/��С 5.��ĳ��ֵ������
// 6.������Ϊrk���� 7.�ұ�ĳ����С�����ֵ 8.�ұ�ĳ���������Сֵ
struct Node {
    int l, r;
    int key, val;  // val�����ֵ
    // cnt��¼�ý��ĸ�����
    // size��¼�Ըýڵ�Ϊ�������������нڵ�ĸ�����֮��
    int cnt, size;
} tr[N];
int root, idx;

void pushup(int p) {  // ��p������������p����Ϣ
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}
int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;  // ��������Ҷ�ڵ㣬����cnt, size����1
    return idx;
}
void build() {  // �������ڱ�
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
    pushup(root);
}
// root�Ǳ仯�ģ�Ҫ�����ã��ж���������ͼ
void zig(int& p) {  // ����
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}
void zag(int& p) {  // ����
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(tr[p].l);
    pushup(p);
}
// �漰������������Ҫ������
void insert(int& p, int key) {  // ��������key
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
// �漰������������Ҫ������
void remove(int& p, int key) {  // ɾ������key
    if (p == 0) return;
    if (tr[p].key == key) {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {  // ����Ҷ�ӽڵ�
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);  // ��ת�����ұ� ����������ɾ��
            } else {
                zag(p);
                remove(tr[p].l, key);  // ��ת������� ����������ɾ��
            }
        } else p = 0;  // ��Ҷ�ӽڵ�
    } else if (tr[p].key > key) remove(tr[p].l, key);
    else remove(tr[p].r, key);
    pushup(p);
}
// get_rank_by_key(root, x) - 1;ע��build()ʱ����һ��-INF
int get_rank_by_key(int p, int key) {  // ����key������
    if (!p) return 0;                  // ������key����0
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    return tr[tr[p].l].size + tr[p].cnt + get_rank_by_key(tr[p].r, key);
}
// get_key_by_rank(root, x + 1); ע��build()ʱ����һ��-INF
int get_key_by_rank(int p, int rank) {  // ��������Ϊrank����
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size - tr[p].cnt);
}
int get_prev(int p, int key) {  // ����С��key�������
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_prev(tr[p].r, key));
}
int get_next(int p, int key) {  // ���ش���key����С��
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
