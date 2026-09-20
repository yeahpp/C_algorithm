// 비원형 이중 연결 리스트
// head, tail 더미 노드 사용
// head->prev = NULL, tail->next = NULL

#include <stdio.h>
#include <stdlib.h>

// init() → 더미 head, tail 생성 및 연결
// Create_DLL() → 새 노드 생성
// Append_DLL() → tail 바로 앞에 삽입
// Between_Append_DLL() -> 중간 삽입 **
// Delete_DLL() → tail 바로 앞의 마지막 데이터 노드 삭제
// Between_Delete_DLL() -> 중간 삭제 **
// Print_DLL() → head->next부터 tail 전까지 출력
// destroy_DLL() → 데이터 노드 → head/tail까지 전부 해제

typedef struct DLL {
    int data;
    struct DLL* next;
    struct DLL* prev;
} DLL;

void init(DLL** head, DLL** tail)
{
    (*head) = malloc(sizeof(DLL));
    if (*head == NULL)
        exit(1);
    (*tail) = malloc(sizeof(DLL));
    if (*tail == NULL) {
        free(*head);
        (*head) = NULL;
        exit(1);
    }
    (*head)->data = 0;
    (*head)->next = *tail;
    (*head)->prev = NULL;

    (*tail)->data = 0;
    (*tail)->next = NULL;
    (*tail)->prev = *head;
}

DLL* Create_DLL()
{
    int a;
    scanf("%d", &a);
    DLL* newnode = malloc(sizeof(DLL));
    if (newnode == NULL)
        exit(1);
    newnode->data = a;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void Between_Append_DLL(DLL* A, DLL* B, DLL* newnode)
{
    A->next = newnode;
    newnode->next = B;
    newnode->prev = A;
    B->prev = newnode;
}
void Append_DLL(DLL* tail, DLL* newnode)
{
    Between_Append_DLL(tail->prev, tail, newnode);
    // newnode->next = tail;
    // newnode->prev = tail->prev;
    // tail->prev->next = newnode;
    // tail->prev = newnode;
}
void Between_Delete_DLL(DLL* A, DLL* B)
{
    DLL* del = A->next;
    A->next = B;
    B->prev = A;
    free(del);
}

void Delete_DLL(DLL* head, DLL* tail)
{
    if (head->next == tail)
        return; // 빈리스트라면 삭제할게 없다.
    Between_Delete_DLL(tail->prev->prev, tail);

    // DLL* del = tail->prev;
    // del->prev->next = tail;
    // tail->prev = del->prev;
    // free(del);
    // del = NULL; => del이 지역변수라 함수가 끝나면 어차피 사라지니까 안해도된다.
}

void Print_DLL(DLL* head, DLL* tail)
{
    DLL* curr = head->next;
    while (curr != tail) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void destroy_DLL(DLL** head, DLL** tail)
{
    DLL* curr = (*head)->next;
    while (curr != *tail) {
        DLL* nextNode = curr->next;
        free(curr);

        curr = nextNode;
    }
    free(*head);
    free(*tail);
    (*head) = NULL;
    (*tail) = NULL;
}
int main()
{
    int input;
    DLL* head = NULL;
    DLL* tail = NULL;
    init(&head, &tail);
    while (1) {
        printf("1.삽입 2.삭제 3.출력\n");
        scanf("%d", &input);
        switch (input) {
        case 1: {
            DLL* newnode = Create_DLL();
            Append_DLL(tail, newnode);
            break;
        }
        case 2:
            Delete_DLL(head, tail);
            break;
        case 3:
            Print_DLL(head, tail);
            break;
        case -1:
            destroy_DLL(&head, &tail);
            return 0;
        default:
            break;
        }
    }

    return 0;
}
