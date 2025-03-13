#include <stdio.h>

#define MAX_N 100005

// ��������ڵ�ṹ��
typedef struct {
    int data;
    int next;
} Node;

Node nodes[MAX_N];

// ��תÿ K ��Ԫ�صĺ���
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
    // ��ȡ�����ͷ�ڵ��ַ���ڵ������� K ֵ
    scanf("%d %d %d", &head, &N, &K);

    // ��ȡÿ���ڵ����Ϣ
    for (int i = 0; i < N; i++) {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        nodes[addr].data = data;
        nodes[addr].next = next;
    }

    // �ռ�����ڵ�ĵ�ַ
    int nodeList[MAX_N];
    int len = 0;
    int current = head;
    while (current != -1) {
        nodeList[len++] = current;
        current = nodes[current].next;
    }

    // ��תÿ K ��Ԫ��
    reverseKGroup(nodeList, len, K);

    // ���½ڵ�� next ָ��
    for (int i = 0; i < len - 1; i++) {
        nodes[nodeList[i]].next = nodeList[i + 1];
    }
    if (len > 0) {
        nodes[nodeList[len - 1]].next = -1;
    }

    // ������
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("%05d %d -1\n", nodeList[i], nodes[nodeList[i]].data);
        } else {
            printf("%05d %d %05d\n", nodeList[i], nodes[nodeList[i]].data, nodes[nodeList[i]].next);
        }
    }

    return 0;
}
