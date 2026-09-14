# C 알고리즘 공부 기록

C언어로 자료구조와 알고리즘을 직접 구현하며 공부한 기록입니다.
주제별로 폴더를 나누고, 하나의 개념을 익힐 때마다 커밋을 남깁니다.

## 목차

| 주제 | 내용 | 위치 |
|------|------|------|
| 재귀 | 재귀의 기본 구조(종료 조건 / 재귀 호출), 팩토리얼, 패턴 출력 | [Recursion/](./Recursion) |
| 연결 리스트 | 단일 연결 리스트, 이중 연결 리스트(원형 더미 노드) | [LinkedList/](./LinkedList) |

## 폴더별 상세

### [Recursion/](./Recursion)

| 파일 | 내용 |
|------|------|
| [recursion.c](./Recursion/recursion.c) | 재귀의 기본 개념 정리와 팩토리얼 구현 |
| [linear_recursion.c](./Recursion/linear_recursion.c) | 선형 재귀로 만드는 출력 패턴 연습 |
| [recursion2.c](./Recursion/recursion2.c) | 배열·누적합을 다루는 재귀 연습 |

### [LinkedList/](./LinkedList)

| 파일 | 내용 |
|------|------|
| [single_linked_list.c](./LinkedList/single_linked_list.c) | 단일 연결 리스트. 더미 head + 끝까지 순회 후 Append |
| [double_linked_list.c](./LinkedList/double_linked_list.c) | 이중 연결 리스트. head/tail 더미를 원형으로 연결해 경계 처리 제거 |

## 빌드 & 실행

각 `.c` 파일은 단독으로 컴파일됩니다.

```sh
cd LinkedList
gcc -Wall -Wextra -g -o dll double_linked_list.c
./dll
```

입력이 필요한 예제는 같은 폴더의 `data.txt` 를 `freopen` 으로 읽으므로,
**해당 폴더 안에서 실행**해야 합니다. 다른 경로에서 실행하면 `freopen` 이
실패해 엉뚱한 값이 나옵니다.

## 코드 스타일

`.clang-format` 을 두어 들여쓰기 4칸, 함수는 중괄호를 다음 줄에,
`if`/`for` 는 같은 줄에 두는 스타일로 통일합니다.
VS Code 에서 저장하면 자동으로 정렬됩니다.
