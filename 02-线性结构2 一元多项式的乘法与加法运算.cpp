#include <stdio.h>
#define MAXSIZE 5000

typedef struct {
    int up;
    int down;
} Num;

int main() {
    Num num1[MAXSIZE];
    Num num2[MAXSIZE];
    int ans1[MAXSIZE] = {0};  // ��ʼ���˻�����ʽ�������
    int ans2[MAXSIZE] = {0};  // ��ʼ���Ͷ���ʽ�������

    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &num1[i].up, &num1[i].down);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &num2[i].up, &num2[i].down);
    }

    // ����˻�����ʽ
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans1[num1[i].down + num2[j].down] += num1[i].up * num2[j].up;
        }
    }

    // ����Ͷ���ʽ
    int temp1 = 0, temp2 = 0;
    while (temp1 < n && temp2 < m) {
        if (num1[temp1].down > num2[temp2].down) {
            ans2[num1[temp1].down] += num1[temp1].up;
            temp1++;
        } else if (num1[temp1].down < num2[temp2].down) {
            ans2[num2[temp2].down] += num2[temp2].up;
            temp2++;
        } else {
            ans2[num2[temp2].down] += num2[temp2].up + num1[temp1].up;
            temp1++;
            temp2++;
        }
    }
    while (temp1 < n) {
        ans2[num1[temp1].down] += num1[temp1].up;
        temp1++;
    }
    while (temp2 < m) {
        ans2[num2[temp2].down] += num2[temp2].up;
        temp2++;
    }

    // ����˻�����ʽ
    int flag1 = 1;
    int first1 = 1;  // ����Ƿ�Ϊ��һ��������
    for (int i = MAXSIZE - 1; i >= 0; i--) {
        if (ans1[i] != 0) {
            if (flag1) {
                printf("%d %d", ans1[i], i);
                flag1 = 0;
                first1 = 0;
            } else {
                printf(" %d %d", ans1[i], i);
            }
        }
    }
    if (flag1) {
        printf("0 0");
    }
    printf("\n");

    // ����Ͷ���ʽ
    int flag2 = 1;
    int first2 = 1;  // ����Ƿ�Ϊ��һ��������
    for (int i = MAXSIZE - 1; i >= 0; i--) {
        if (ans2[i] != 0) {
            if (flag2) {
                printf("%d %d", ans2[i], i);
                flag2 = 0;
                first2 = 0;
            } else {
                printf(" %d %d", ans2[i], i);
            }
        }
    }
    if (flag2) {
        printf("0 0");
    }

    return 0;
}
