#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX (101)

int queue[MAX];
int front, rear;

int arr[MAX][MAX] = {0};
int V;

// BFS
int virus_bfs(int start)
{
    int used[MAX] = {0};
    int cnt = 0;

    front = rear = 0;

    // 시작 정점 큐에 삽입
    queue[rear++] = start;

    // 시작 정점 방문 처리
    used[start] = 1;

    while (front != rear) {
        // 큐에서 하나 꺼내기
        int curr = queue[front++];

        // curr와 연결되어 있는 정점만 확인
        for (int i = 1; i <= arr[curr][0]; ++i) {
            int next = arr[curr][i];

            // 아직 방문하지 않았다면
            if (used[next] == 0) {
                // 방문 처리
                used[next] = 1;

                // 큐에 삽입
                queue[rear++] = next;

                // 감염된 컴퓨터 수 증가
                ++cnt;
            }
        }
    }

    return cnt;
}

// 그래프 출력
void print_arr(int (*arr)[MAX], int V)
{
    for (int i = 1; i <= V; ++i) {
        printf("%d : ", i);

        // [0]에는 연결 개수가 들어있으므로
        // [1]부터 출력
        for (int j = 1; j <= arr[i][0]; ++j) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    int E;
    int v1, v2;

    (void)freopen("data.txt", "r", stdin);

    // V : 정점 개수
    // E : 간선 개수
    (void)scanf("%d %d", &V, &E);

    // 간선 입력
    for (int i = 0; i < E; ++i) {
        (void)scanf("%d %d", &v1, &v2);

        // v1 → v2 연결
        arr[v1][++arr[v1][0]] = v2;

        // v2 → v1 연결
        arr[v2][++arr[v2][0]] = v1;
    }

    // 그래프 출력
    print_arr(arr, V);

    // 1번 컴퓨터부터 BFS
    int result = virus_bfs(1);

    printf("감염된 컴퓨터 수 : %d\n", result);

    return 0;
}
