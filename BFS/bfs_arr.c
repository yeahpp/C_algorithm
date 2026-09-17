#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// 1. 그래프를 2차원 배열 형태로 출력함
void printArr(int (*arr)[MAX], int v)
{
    for (int i = 1; i <= v; ++i) // i 가 1 부터 하는 이유는 노드가 1번 부터 시작하기 때문에
    {
        for (int k = 1; k <= v; ++k) {
            printf("%d ", arr[i][k]);
        }
        printf("\n");
    }
}
// 2.
// 너비 우선 탐색(BFS)은 큐를 이용하여
// 현재 노드와 인접한 노드들을 먼저 방문한다.
// 시작 노드에서 가까운 노드부터 순서대로 탐색하고 출력해보자

// BFS 작동원리
// 출발점을 큐에 넣어.
// 큐에서 첫번째 정점을 빼고(++front), 뺀 정점을 출력해 (출력된 정점은 가까운 노드를 의미)
// 뺀 정점과 연결된 다른 정점들을 큐에 넣어 (++rear)
// 단 이미 큐에서 넣은 정점들은 다시 큐에 안넣음 => used[] 이용
// 다시 큐에서 첫번째 정점을 꺼내, 출력 (++front)
// 뺀 정점과 연결된 다른 정점을 큐에 넣어 (++rear)
// 이 동작이 계속 반복됨

void virus_bfs(int start, int v, int (*arr)[MAX])
{

    int used[MAX] = {0};
    int queue[MAX] = {0};
    int front = 0;
    int rear = 0;

    queue[++rear] = start;         // 출발점을 큐에 넣어.
    used[start] = 1;               // 큐에 넣은 정점을 인덱스 번호로 사용해서 해당 배열자리에 1을 입력
    while (front < rear) {         // rear = front 는 공백을 의미하므로 그 전까지 반복
        int curr = queue[++front]; // 큐에서 첫번째 정점 빼고,
        printf("%d ", curr);       // 뺀 정점을 출력
        for (int i = 1; i <= v; ++i) {
            if (arr[curr][i] == 1 && used[i] != 1) { // 뺀 정점과 연결된 정점들을 큐에 넣어. 단 used[]=1 인것, 즉 이미 사용한 거는 ㄴㄴ
                queue[++rear] = i;
                // 연결된 정점들을 큐에 넣는 코드, (i)는 그래프의 열을 의미, 즉 curr은 우리가 방금 큐에서 꺼낸 정점인데,
                // 그 정점(행)을 시작으로 도착지(열) 즉 i 으로 가리키는 배열요소의 위치가 1이면
                // i는 curr과 연결되어있는 정점들이다.

                used[i] = 1; // 연결된 정점 i를 사용했다고 하는 코드
            }
        }
    }
}

int main()
{
    int v, e;
    int v1, v2;
    int arr[MAX][MAX] = {0};
    (void)freopen("bfsdata.txt", "r", stdin);
    (void)scanf("%d %d", &v, &e);
    for (int i = 0; i < e; ++i) { // e는 간선의 개수, 즉 정점과 정점이 이어진 수 만큼 해당 배열에 위치에다가 1을 넣으면 되니까 for문에 사용
        (void)scanf("%d %d", &v1, &v2);
        arr[v1][v2] = arr[v2][v1] = 1;
    }
    printArr(arr, v);
    virus_bfs(1, v, arr);

    return 0;
}
