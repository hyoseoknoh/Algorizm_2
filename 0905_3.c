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

// 새로운 데이터를 리스트의 끝에 삽입
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

// 새로운 데이터를 리스트의 앞에 삽입
void dinsert_front(DListNode* head, element data) {
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;

    // 리스트의 첫 번째 노드 앞에 삽입
    newnode->rlink = head->rlink;
    newnode->llink = head;
    head->rlink->llink = newnode;
    head->rlink = newnode;
}

// 특정 노드 뒤에 새로운 데이터를 삽입
void dinsert_after(DListNode* prev, element data) {
    if (prev == NULL) return;  // 예외 처리: 이전 노드가 NULL인 경우 함수 종료
    DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
    newnode->data = data;

    // 새 노드를 이전 노드의 오른쪽에 삽입
    newnode->rlink = prev->rlink;  // 새 노드의 오른쪽 링크를 이전 노드의 오른쪽 링크로 설정
    newnode->llink = prev;  // 새 노드의 왼쪽 링크를 이전 노드로 설정
    prev->rlink->llink = newnode;  // 이전 노드의 오른쪽 노드의 왼쪽 링크를 새 노드로 설정
    prev->rlink = newnode;  // 이전 노드의 오른쪽 링크를 새 노드로 설정
}

// 노드 삭제
void ddelete(DListNode* head, DListNode* removed) {
    if (removed == head) return;  // 예외 처리: 삭제할 노드가 head인 경우 함수 종료
    removed->llink->rlink = removed->rlink;  // 삭제할 노드의 왼쪽 노드의 오른쪽 링크를 삭제할 노드의 오른쪽 노드로 설정
    removed->rlink->llink = removed->llink;  // 삭제할 노드의 오른쪽 노드의 왼쪽 링크를 삭제할 노드의 왼쪽 노드로 설정
    free(removed);  // 삭제할 노드의 메모리를 해제
}

// 이중 연결 리스트
int main(void) {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);

    // 1. Doubly Linked List 생성 후 10, 20, 30, 40, 50 순서대로 삽입
    printf("(1) 10, 20, 30, 40, 50 추가\n");
    for (int i = 10; i <= 50; i += 10) {
        dinsert_end(head, i);
    }
    print_dlist(head);

    printf("\n");

    // 2. 리스트 가장 왼쪽에 5 삽입
    printf("(2) 리스트 가장 왼쪽에 5 삽입\n");
    dinsert_front(head, 5);
    print_dlist(head);

    printf("\n");

    // 3. 리스트 가장 오른쪽에 60 삽입
    printf("(3) 리스트 가장 오른쪽에 60 삽입\n");
    dinsert_end(head, 60);
    print_dlist(head);
    printf("\n");

    // 4. 20과 30 사이에 25 삽입
    printf("(4) 20과 30 사이에 25 삽입\n");
    DListNode* current = head->rlink;  // 리스트의 첫 번째 노드로부터 시작
    while (current != head && current->data != 20) {  // 리스트의 끝(head) 또는 데이터가 20인 노드를 찾을 때까지 반복
        current = current->rlink;  // 다음 노드로 이동
    }
    if (current != head) {  // 만약 현재 노드가 head가 아니라면, 즉 데이터가 20인 노드를 찾았다면
        dinsert_after(current, 25);  // 20 노드 뒤에 25 노드를 삽입
    }
    print_dlist(head);
    printf("\n");

    // 5. 40 삭제
    printf("(5) 40 삭제\n");
    current = head->rlink;  // 리스트의 첫 번째 노드로부터 시작
    while (current != head && current->data != 40) {  // 리스트의 끝(head) 또는 데이터가 40인 노드를 찾을 때까지 반복
        current = current->rlink;  // 다음 노드로 이동
    }
    if (current != head) {  // 만약 현재 노드가 head가 아니라면, 즉 데이터가 40인 노드를 찾았다면
        ddelete(head, current);  // 40 노드를 삭제
    }
    print_dlist(head);
    printf("\n");

    return 0;
}
