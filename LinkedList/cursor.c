// CLL 로 알고리즘 문제 풀어보기

// L : 커서를 한 문자 왼쪽으로 이동 (커서가 시작 부분에 있으면 아무것도 하지 않음)
// D : 커서를 한 문자 오른쪽으로 이동 (커서가 끝 부분에 있으면 아무것도 하지 않음)
// B : 커서 왼쪽의 문자를 삭제 (커서가 시작 부분에 있으면 아무것도 하지 않음)
// P $ : 커서 왼쪽에 문자 $를 추가 (문자 $는 영어 알파벳의 소문자)
// 주어진 연산들을 실행하기 전에 커서는 텍스트의 끝에 위치합니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void init(Node** head)
{
    *head = (Node*)calloc(1, sizeof(Node));
    if (*head == NULL)
        exit(1);

    (*head)->next = (*head);
    (*head)->prev = (*head);
    return;
}

void plus(Node* head, char cmd)
{
    Node* newnode = calloc(1, sizeof(Node));
    if (newnode == NULL)
        exit(1);
    newnode->data = cmd;
    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
    return;
}

void L_DELETE(Node* head, Node* cursor)
{
    if (cursor != head) {
        cursor->prev->next = cursor->next;
        cursor->next = cursor->prev;
        cursor = cursor->prev;
    }
}

int main()
{
    Node* head = NULL;
    init(&head);
    char* cmd;
    char a, b;
    int n;
    (void)scanf("%s", &cmd);
    (void)scanf("%d", &n);
    int count = strln(cmd);
    for (int i = 0; i < count; ++i) {
        // 왼쪽 삽입-> 뒤로 삽입
        plus(head, cmd[i]);
    }
    Node* cursor = head->prev; // 맨 뒤에 커서

    for (int i = 0; i < n; ++i) {
        (void)scanf(" %c", &a);
        if (a == 'L') {
            if (cursor != head) {
                cursor = cursor->prev;
            }
        } else if (a == 'D') {
            if (cursor->next != head) {
                cursor = cursor->next;
            }
        } else if (a == 'B') {
            L_DELETE(head, cursor);
        } else if (a == 'P') {
            (void)scanf(" %c", &b);
            PLUS_C(head, cursor, b);
        }
    }

    return 0;
}
