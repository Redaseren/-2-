/*请设计时间和空间上都尽可能高效的算法，在不改变链表的前提下，
求链式存储的线性表的倒数第m（>0）个元素。*/

#include<stdio.h>
#define ERROR -1

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

/*创建一个大小为m的数组，则倒数第m个数必定位于这个数组内*/
/*既如果最后一个数据如果位于k号位置，则倒数第m个元素的位置应该为[k-（m-1)],
即（k+1）-m，考虑到一个循环长度为m，实际位置为[(k+1)-m]%m,既为（k+1）%m*/
ElementType Find(List L, int m) {
    List* A = malloc(m * sizeof(List));
    /*初始化数组*/
    for (int i = 0; i < m; i++)
        A[i] = NULL;
    if (!L) return ERROR;
    int rear = 0;
    while (L) {
        A[rear] = L;
        rear = (rear + 1) % m;
        L = L->Next;
    }
    if (A[rear] == NULL)
        return ERROR;
    return A[rear]->Data;
}

/*释放结点*/
void Free(List L) {
    List t;
    while (L) {
        t = L;
        L = t->Next;
        free(t);
    }
}


/*可以建一个堆栈，然后抛出堆栈中的第m个元素即可*/
/*由于不知道原先链表中的元素，因此堆栈可以用链表存储*/
typedef struct SNode *PtrToSNode;
struct SNode {
    List L; 
    PtrToSNode Next;
};

typedef PtrToSNode Stack;

/*创建一个堆栈的头结点*/
Stack CreateStack() {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/*判断堆栈是否为空*/
int IsEmpty(Stack S) {
    if (S->Next == NULL)
        return 1;
    else
        return 0;
}

/*向堆栈中加入元素*/
void Push(Stack S, List L) {
    Stack T = CreateStack();
    T->L = L;
    T->Next = S->Next;
    S->Next = T;
    return ;
}

/*从堆栈中抛出元素*/
List Pop(Stack S) {
    List L = NULL;
    Stack T = NULL;
   if (!IsEmpty(S)) {
       T = S->Next;
       L = T->L;
       S->Next = T->Next;
       free(T);
    }
   return L;
}

/*释放堆栈及链表L所占的空间*/
void Free(Stack S, List L) {
    /*释放堆栈*/
    Stack TS = NULL;
    while (!IsEmpty(S)) {
        TS = S->Next;
        S->Next = TS->Next;
        free(TS);
    }
    free(S);

    /*释放链表所占的空间*/
    List TL = NULL;
    while (L) {
        TL = L;
        L = L->Next;
        free(TL);
    }
    return;
}

ElementType Find(List L, int m) {
   List posit = L; /*暂存L头结点*/
   int count = 0; /*记录元素的总个数*/
   ElementType X = ERROR; /*记录要返回的元素*/
   Stack S = CreateStack();
   Stack Temp = S; /*暂存S头结点*/
   /*把元素加入堆栈中*/
   while (L) {
       Push(S, L);
       L = L->Next;
       count++;
   }

   L = posit;

   /*元素不够*/
   if (count < m) {
       Free(S, L);
       return ERROR;
   }

   if (count / 2 < m) {/*元素在后半段*/
       /*抛出堆栈中的第m个元素*/
       for (int i = 0; i < m; i++) {
           S = S->Next;
       }
       X = S->L->Data;
       S = Temp;
   }
   else {/*元素在前半段*/
       for (int i = 1; i < m; i++) {
           L = L->Next;
       }
       X = L->Data;
       L = posit;
   }

   Free(S, L);
   return X;
}




int main() {

	return 0;
}