#include <stdio.h>
#include <stdlib.h>

// 연결리스트를 이용해서 BFS 구현
// 정점의 개수에 따라 포인터배열 동적할당
// 해당 포인터 배열은 정점의 정보를 저장하는 노드들을 가리킴 (newnode 동적할당)
// 포인터 배열이 처음 가리키는 노드는 해당 정점이 몇개와 연결되어있는지 개수를 알려줌

// 배열보다 연결리스트를 이용해서 BFS를 사용하면
// 간선이 적은 그래프는 모든 정점을 순회할필요없이, 리스트를 통해서 어떤 정점과 연결되어있는지
// 바로 알 수 있어서 좋다.

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node** init(int v)
{
    Node** phead = (Node**)calloc(v + 1, sizeof(Node*)); // 1번부터 시작해서
    if (phead == NULL)
        exit(1);
    return phead;
}

Node* create_node(int data)
{
    Node* newnode = malloc(sizeof(Node));
    if (newnode == NULL)
        exit(1);
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_node(Node** phead, int from, int to)
{
    Node* newnode = create_node(to);
    newnode->next = phead[from]; // 새 노드의 next에 기존 첫 번째 노드의 주소를 저장해.
    phead[from] = newnode;
}

void print_graph(Node** phead, int v)
{
    for (int i = 1; i <= v; ++i) {
        printf("%d : ", i);

        Node* curr = phead[i];

        while (curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }

        printf("\n");
    }
}
int main()
{
    int v, e;
    int v1, v2;
    (void)freopen("bfsdata.txt", "r", stdin);
    (void)scanf("%d %d", &v, &e);
    Node** phead = init(v); // 포인터 배열을 가리키는 포인터 => ( Node*)를 가리키는 * 변수
    for (int i = 0; i < e; ++i) {
        {
            scanf("%d %d", &v1, &v2);
            insert_node(phead, v1, v2);
            insert_node(phead, v2, v1);
        }
    }
    print_graph(phead, v);

    return 0;
}
