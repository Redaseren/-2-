#include<stdio.h>
typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

/*假设链表有头结点*/
List Insert(List L, ElementType X)
{
    if (!L) {
        printf("链表头结点为空，不符合题意，建议重新创建链表头结点");
        return L;
    }

    List left= L; /*指向应插入位置的前一个结点*/
    List right = L->Next; /*指向应插入位置的后一个结点*/

    /*创建一个临时结点，用于存储数据*/
    List Temp = (List)malloc(sizeof(struct Node));
    Temp->Next = right;

    while (!right) {
        if (X > right) {
            left = right;
            right = right->Next;
        }
        else
            break;
    }
   
    Temp->Data = X;
    left->Next = Temp;
    return L;
}
int main() {


	return 0;
}