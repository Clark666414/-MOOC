#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
Position BinarySearch( List L, ElementType X ) {
    Position left = 1;  // 左边界，元素从下标1开始存储
    Position right = L->Last;  // 右边界

    while (left <= right) {
        Position mid = (left + right) / 2;  // 计算中间位置，简化计算方式

        if (L->Data[mid] == X) {
            return mid;  // 找到目标元素，返回下标
        } else if (L->Data[mid] < X) {
            left = mid + 1;  // 目标元素在右半部分
        } else {
            right = mid - 1;  // 目标元素在左半部分
        }
    }

    return NotFound;  // 未找到目标元素，返回 NotFound
}
