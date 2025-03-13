#include <stdio.h>

#define MAX_N 100005

// 定义链表节点结构体
typedef struct {
    int data;
    int next;
} Node;

Node nodes[MAX_N];

// 反转每 K 个元素的函数
void reverseKGroup(int *nodeList, int len, int K) {
    for (int i = 0; i + K <= len; i += K) {
        int left = i, right = i + K - 1;
        while (left < right) {
            int temp = nodeList[left];
            nodeList[left] = nodeList[right];
            nodeList[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int head, N, K;
    // 读取输入的头节点地址、节点总数和 K 值
    scanf("%d %d %d", &head, &N, &K);

    // 读取每个节点的信息
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
    }

    // 收集链表节点的地址
    int nodeList[MAX_N];
    int len = 0;
    int current = head;
    while (current != -1) {
        nodeList[len++] = current;
        current = nodes[current].next;
    }

    // 反转每 K 个元素
    reverseKGroup(nodeList, len, K);

    // 更新节点的 next 指针
    for (int i = 0; i < len - 1; i++) {
        nodes[nodeList[i]].next = nodeList[i + 1];
    }
    if (len > 0) {
        nodes[nodeList[len - 1]].next = -1;
    }

    // 输出结果
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("%05d %d -1\n", nodeList[i], nodes[nodeList[i]].data);
        } else {
            printf("%05d %d %05d\n", nodeList[i], nodes[nodeList[i]].data, nodes[nodeList[i]].next);
        }
    }

    return 0;
}
