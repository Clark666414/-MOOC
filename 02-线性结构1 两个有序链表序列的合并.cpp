#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 ) {
    // ����һ���µ�ͷ���
    List L = (List)malloc(sizeof(List));
    L->Next = NULL;
    List tail = L;  // ����ָ���������β�ڵ�

    // �������������ͷ���
    PtrToNode p1 = L1->Next;
    PtrToNode p2 = L2->Next;

    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            tail->Next = p1;
            p1 = p1->Next;
        } else {
            tail->Next = p2;
            p2 = p2->Next;
        }
        tail = tail->Next;
    }

    // ��ʣ��Ľڵ�ӵ�������β��
    if (p1 != NULL) {
        tail->Next = p1;
    }
    if (p2 != NULL) {
        tail->Next = p2;
    }

    // ���ԭ�����ͷ����Nextָ��
    L1->Next = NULL;
    L2->Next = NULL;

    return L;
}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
