/*����Ҫ��ʵ��һ�������������������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ����������С�*/
#include<stdio.h>
typedef int ElementType;
typedef struct Node* PtrToNode;

struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */


/*�ϲ�����*/
List Merge(List L1, List L2) {
    List Head = (List)malloc(sizeof(struct Node));
    List rear=Head;  /*������Ҫ�����λ��*/
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