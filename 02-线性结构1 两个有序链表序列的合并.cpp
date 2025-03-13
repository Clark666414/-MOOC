#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 ) {
    // 创建一个新的头结点
    List L = (List)malloc(sizeof(List));
    L->Next = NULL;
    List tail = L;  // 用于指向新链表的尾节点

    // 跳过两个链表的头结点
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

    // 将剩余的节点接到新链表尾部
    if (p1 != NULL) {
        tail->Next = p1;
    }
    if (p2 != NULL) {
        tail->Next = p2;
    }

    // 清空原链表的头结点的Next指针
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
