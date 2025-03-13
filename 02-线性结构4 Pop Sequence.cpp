#include <stdio.h>

#define MAXSIZE 1000

// �ж�һ�������Ƿ�Ϊ�Ϸ���ջ��������
int is_valid_sequence(int stack_capacity, int sequence_length, int sequence[]) {
    int stack[MAXSIZE];
    int top = -1;  // ջ��ָ��
    int push_num = 1;  // ��ѹ���Ԫ��
    int pop_index = 0;  // ��ǰҪ������Ԫ�ص�����

    while (pop_index < sequence_length) {
        // ���ջΪ�ջ���ջ��Ԫ�ز����ڵ�ǰҪ������Ԫ��
        if (top == -1 || stack[top] != sequence[pop_index]) {
            // ѹ��Ԫ��ֱ��ջ��Ԫ�ص��ڵ�ǰҪ������Ԫ�ػ���ջ����
            while (push_num <= sequence_length && top + 1 < stack_capacity) {
                stack[++top] = push_num++;
                if (stack[top] == sequence[pop_index]) {
                    break;
                }
            }
            // ���ջ��Ԫ����Ȼ�����ڵ�ǰҪ������Ԫ�أ�˵�����в��Ϸ�
            if (stack[top] != sequence[pop_index]) {
                return 0;
            }
        }
        // ����ջ��Ԫ��
        top--;
        pop_index++;
    }
    // �������Ԫ�ض����������ջΪ�գ�˵�����кϷ�
    return top == -1;
}

int main() {
    int m, n, k;
    int sequence[MAXSIZE];

    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &sequence[j]);
        }
        if (is_valid_sequence(m, n, sequence)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
