#include <stdio.h>

#define MAXSIZE 1000

// 判断一个序列是否为合法的栈弹出序列
int is_valid_sequence(int stack_capacity, int sequence_length, int sequence[]) {
    int stack[MAXSIZE];
    int top = -1;  // 栈顶指针
    int push_num = 1;  // 待压入的元素
    int pop_index = 0;  // 当前要弹出的元素的索引

    while (pop_index < sequence_length) {
        // 如果栈为空或者栈顶元素不等于当前要弹出的元素
        if (top == -1 || stack[top] != sequence[pop_index]) {
            // 压入元素直到栈顶元素等于当前要弹出的元素或者栈已满
            while (push_num <= sequence_length && top + 1 < stack_capacity) {
                stack[++top] = push_num++;
                if (stack[top] == sequence[pop_index]) {
                    break;
                }
            }
            // 如果栈顶元素仍然不等于当前要弹出的元素，说明序列不合法
            if (stack[top] != sequence[pop_index]) {
                return 0;
            }
        }
        // 弹出栈顶元素
        top--;
        pop_index++;
    }
    // 如果所有元素都处理完毕且栈为空，说明序列合法
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
