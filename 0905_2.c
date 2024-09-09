// #include <stdio.h>
// #include <stdlib.h>

// typedef int element;
// typedef struct DListNode{
//     element data;
//     struct DListNode* llink;
//     struct DListNode* rlink;
// } DListNode;
// //이중 연결 리스트 초기화
// void init(DListNode* phead){
//     phead->llink = phead;
//     phead->rlink = phead;
// }

// //이중 연결 리스트노드 출력
// void print_dlist(DListNode* phead){
//     DListNode* p;
//     for(p = phead->rlink; p!=phead; p=p->rlink){
//         printf("<-| |%d| |->",p->data);
//     }
//     printf("\n");
// }

// //새로운 데이터를 노트 before의 오른쪽에 삽입..
// void dinsert(DListNode *before, element data){
//     DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
//     newnode->data = data;
//     newnode->llink = before;
//     newnode->rlink = before->rlink;
//     before->rlink->llink = newnode;
//     before->rlink = newnode;
// }

// //노드 removed삭제..
// void ddelte(DListNode* head, DListNode* removed){
//     if(removed == head) return;
//     removed->llink->rlink = removed->rlink;
//     removed->rlink->llink = removed->llink;
//     free(removed);
// }

// //이중 연결리스트 
// int main(void){
//     DListNode* head = (DListNode *)malloc(sizeof(DListNode));
//     init(head);
//     printf("10 20 30 40 50 추가");
//     for(int i=10; i<=50; i+=10){
//         dinsert(head, i);
//         print_dlist(head);
//     }
    
// }

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트 초기화
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중 연결 리스트 노드 출력
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |->", p->data);
    }
    printf("\n");
}

// 새로운 데이터를 리스트의 마지막에 삽입
void dinsert_end(DListNode* head, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;

    // 리스트의 마지막 노드를 찾아 삽입
    DListNode* tail = head->llink;
    newnode->llink = tail;
    newnode->rlink = head;
    tail->rlink = newnode;
    head->llink = newnode;
}

// 노드 removed 삭제
void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

// 이중 연결 리스트
int main(void) {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    printf("10 20 30 40 50 추가\n");
    
    for (int i = 10; i <= 50; i += 10) {
        dinsert_end(head, i);
        print_dlist(head);
    }

    return 0;
}
