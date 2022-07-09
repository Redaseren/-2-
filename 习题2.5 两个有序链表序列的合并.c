/*本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。*/
#include<stdio.h>
typedef int ElementType;
typedef struct Node* PtrToNode;

struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */


/*合并函数*/
List Merge(List L1, List L2) {
    List Head = (List)malloc(sizeof(struct Node));
    List rear=Head;  /*新链表要插入的位置*/
    while (L1 && L2) {
        if (L1->Data > L2->Data) {
            rear->Next = L1;
            L1 = L1->Next;
            rear = rear->Next;
        }
        else {
            rear->Next = L2;
            L2 = L2->Next;
            rear = rear->Next;
        }
    }

    if (!L1) {
        rear->Next = L2;
    }
    else if (!L2 ) {
        rear->Next = L1;
    }

    L1 = Head->Next;
    free(Head);

    return L1;
}