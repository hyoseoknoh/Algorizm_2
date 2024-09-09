#include <stdio.h>
#include <stdlib.h>

// 이중 연결 리스트 노드 정의
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// 새로운 노드를 생성하는 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// 리스트의 앞쪽에 노드를 삽입하는 함수
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// 리스트의 뒤쪽에 노드를 삽입하는 함수
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// 특정 노드 뒤에 노드를 삽입하는 함수
void insertAfterNode(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// 리스트를 출력하는 함수
void printList(Node* node) {
    Node* last;
    printf("Forward: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // 초기 리스트 생성: 10-20-30-40-50
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    // 앞쪽에 5 삽입
    insertAtFront(&head, 5);

    // 뒤쪽에 60 삽입
    insertAtEnd(&head, 60);

    // 20과 30 사이에 25 삽입
    Node* temp = head;
    while (temp != NULL && temp->data != 20) {
        temp = temp->next;
    }
    if (temp != NULL) {
        insertAfterNode(temp, 25);
    }

    // 리스트 출력
    printList(head);

    return 0;
}
