// 원형 이중 연결 리스트
// head, tail 더미 노드 사용해서
// head->prev = tail, tail->next = head 사용 할 수 있지만,
// BUT tail을 사용 X head라는 노드 더미만 사용할 것
// 더미 head 노드 하나만 사용
// head->next : 첫 번째 데이터 노드
// head->prev : 마지막 데이터 노드

#include <stdio.h>
#include <stdlib.h>

// init() → 더미 head  생성 및 연결
// Create_DLL() → 새 노드 생성
// Append_DLL() → head -> prev -> next 삽입
// Between_Append_DLL() -> 중간 삽입 **
// Delete_DLL() → head->prev 인 데이터 노드 삭제
// Between_Delete_DLL() -> 중간 삭제 **
// Print_DLL() → head->next부터 head가 나올 떄까지 출력
// destroy_DLL() → 데이터 노드 → head 해제

typedef struct DLL {
    int data;
    struct DLL* next;
    struct DLL* prev;
} DLL;

void init(DLL** head)
{
    (*head) = malloc(sizeof(DLL));
    if (*head == NULL)
        exit(1);
    (*head)->data = 0;
    (*head)->next = *head;
    (*head)->prev = *head;
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
    // head 바로 앞에 삽입이라고 할 때
    // head -> prev는 맨 처음 새 노드를 생성할 때만 설정되고, 그 뒤로는 접근 불가기 때문에
    // head -> next 에 새로운 노드가 생성되어도, head->prev는 바뀌지 않는다.
    A->next = newnode;
    newnode->next = B;
    newnode->prev = A;
    B->prev = newnode;
}
void Append_DLL(DLL* head, DLL* newnode)
{
    Between_Append_DLL(head->prev, head, newnode);
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

void Delete_DLL(DLL* head)
{
    if (head->next == head)
        return; // 빈리스트라면 삭제할게 없다.
    Between_Delete_DLL(head->prev->prev, head);

    // DLL* del = tail->prev;
    // del->prev->next = tail;
    // tail->prev = del->prev;
    // free(del);
    // del = NULL; => del이 지역변수라 함수가 끝나면 어차피 사라지니까 안해도된다.
}

void Print_DLL(DLL* head)
{
    DLL* curr = head->next;
    while (curr != head) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void destroy_DLL(DLL** head)
{
    DLL* curr = (*head)->next;
    while (curr != *head) {
        DLL* nextNode = curr->next;
        free(curr);

        curr = nextNode;
    }
    free(*head);
    (*head) = NULL;
}
int main()
{
    int input;
    DLL* head = NULL;
    init(&head);
    while (1) {
        printf("1.삽입 2.삭제 3.출력\n");
        scanf("%d", &input);
        switch (input) {
        case 1: {
            DLL* newnode = Create_DLL();
            Append_DLL(head, newnode);
            break;
        }
        case 2:
            Delete_DLL(head);
            break;
        case 3:
            Print_DLL(head);
            break;
        case -1:
            destroy_DLL(&head);
            return 0;
        default:
            break;
        }
    }

    return 0;
}
