#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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
    Position left = 1;  // ��߽磬Ԫ�ش��±�1��ʼ�洢
    Position right = L->Last;  // �ұ߽�

    while (left <= right) {
        Position mid = (left + right) / 2;  // �����м�λ�ã��򻯼��㷽ʽ

        if (L->Data[mid] == X) {
            return mid;  // �ҵ�Ŀ��Ԫ�أ������±�
        } else if (L->Data[mid] < X) {
            left = mid + 1;  // Ŀ��Ԫ�����Ұ벿��
        } else {
            right = mid - 1;  // Ŀ��Ԫ������벿��
        }
    }

    return NotFound;  // δ�ҵ�Ŀ��Ԫ�أ����� NotFound
}
