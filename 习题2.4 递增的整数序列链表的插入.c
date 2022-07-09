#include<stdio.h>
typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data; /* �洢������� */
    PtrToNode   Next; /* ָ����һ������ָ�� */
};
typedef PtrToNode List; /* ���嵥�������� */

/*����������ͷ���*/
List Insert(List L, ElementType X)
{
    if (!L) {
        printf("����ͷ���Ϊ�գ����������⣬�������´�������ͷ���");
        return L;
    }

    List left= L; /*ָ��Ӧ����λ�õ�ǰһ�����*/
    List right = L->Next; /*ָ��Ӧ����λ�õĺ�һ�����*/

    /*����һ����ʱ��㣬���ڴ洢����*/
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