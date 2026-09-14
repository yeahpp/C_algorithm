/*
 * recursion.c - 기본 재귀(recursion) 함수 모음
 *
 * 재귀 함수는 자기 자신을 다시 호출하는 함수이다.
 * 재귀 함수를 만들 때는 반드시 아래 두 가지가 있어야 한다.
 *   1) 종료 조건(base case)  : 더 이상 자기 자신을 부르지 않고 끝나는 조건
 *   2) 재귀 호출(recursive case) : 문제를 더 작은 크기로 줄여서 자신을 호출
 * 종료 조건이 없으면 호출이 무한히 쌓여 스택 오버플로가 발생한다.
 */

#include <stdio.h>

/*
 * factorial - n 팩토리얼(n!)을 구한다.
 *
 * 정의: n! = n * (n-1) * (n-2) * ... * 1,  단 0! = 1
 * 점화식: factorial(n) = n * factorial(n - 1)
 *
 * 예) factorial(5)
 *     = 5 * factorial(4)
 *     = 5 * 4 * factorial(3)
 *     = ... = 5 * 4 * 3 * 2 * 1 = 120
 *
 * 반환형이 long long인 이유: 팩토리얼은 매우 빠르게 커져서
 * int(약 21억)로는 13! 부터 값이 넘쳐버리기 때문이다.
 */
long long factorial(int n)
{
    // 종료 조건: 0! 과 1! 은 모두 1이므로 여기서 재귀를 멈춘다.
    if (n <= 1)
        return 1;

    // 재귀 호출: n 에 (n-1)! 을 곱한다.
    // (long long)n 으로 형변환하는 이유는 곱셈이 int끼리 먼저 계산되어
    // 값이 넘치는 것을 막기 위해서다.
    return (long long)n * factorial(n - 1);
}

/*
 * sum_to - 1부터 n까지의 합을 구한다.
 *
 * 점화식: sum_to(n) = n + sum_to(n - 1)
 *
 * 예) sum_to(3) = 3 + sum_to(2) = 3 + 2 + sum_to(1) = 3 + 2 + 1 + 0 = 6
 */
int sum_to(int n)
{
    // 종료 조건: 더할 수가 남지 않았으면 0을 반환한다.
    // (n이 음수로 들어와도 여기서 멈추므로 무한 재귀가 되지 않는다.)
    if (n <= 0)
        return 0;

    // 재귀 호출: 현재 수 n 에 "그 아래 수들의 합"을 더한다.
    return n + sum_to(n - 1);
}

/*
 * fibonacci - n번째 피보나치 수를 구한다.
 *
 * 수열: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...
 * 정의: F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)
 *
 * 주의: 이 방식은 같은 값을 여러 번 중복 계산하기 때문에
 * 호출 횟수가 대략 2^n 에 비례해 늘어난다(매우 느림).
 * n이 40을 넘어가면 눈에 띄게 오래 걸리며,
 * 실제로는 반복문이나 메모이제이션(계산 결과 저장)을 쓰는 것이 좋다.
 */
int fibonacci(int n)
{
    // 종료 조건: F(0) = 0, F(1) = 1 이므로 n 을 그대로 반환하면 된다.
    if (n < 2)
        return n;

    // 재귀 호출: 바로 앞 두 항을 더한다. 호출이 두 갈래로 갈라진다.
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/*
 * gcd - 두 수의 최대공약수를 구한다 (유클리드 호제법).
 *
 * 원리: a 를 b 로 나눈 나머지를 r 이라 할 때, gcd(a, b) = gcd(b, r) 이다.
 *       나머지는 계속 작아지므로 언젠가 반드시 0이 되고, 그때의 b가 답이다.
 *
 * 예) gcd(48, 18)
 *     -> gcd(18, 48 % 18 = 12)
 *     -> gcd(12, 18 % 12 = 6)
 *     -> gcd(6,  12 % 6  = 0)
 *     -> b가 0이므로 6 반환
 */
int gcd(int a, int b)
{
    // 종료 조건: 나머지가 0이 되면 그때의 a 가 최대공약수다.
    if (b == 0)
        return a;

    // 재귀 호출: (b, a를 b로 나눈 나머지) 로 문제를 줄인다.
    // a < b 인 경우에도 a % b == a 가 되어 자동으로 자리가 바뀌므로
    // 미리 크기를 비교해 줄 필요가 없다.
    return gcd(b, a % b);
}

/*
 * power - base 의 exp 제곱(base^exp)을 구한다.
 *
 * 점화식: power(base, exp) = base * power(base, exp - 1)
 *
 * 예) power(2, 3) = 2 * power(2, 2) = 2 * 2 * power(2, 1)
 *                 = 2 * 2 * 2 * power(2, 0) = 2 * 2 * 2 * 1 = 8
 *
 * 참고: 지수가 음수인 경우는 정수로 표현할 수 없으므로 다루지 않는다.
 */
long long power(int base, int exp)
{
    // 종료 조건: 어떤 수든 0제곱은 1이다.
    if (exp == 0)
        return 1;

    // 재귀 호출: base 를 한 번 곱하고 지수를 1 줄인다.
    return (long long)base * power(base, exp - 1);
}

/*
 * reverse_print - 문자열을 거꾸로 출력한다.
 *
 * 핵심: "먼저 재귀 호출을 하고, 그다음에 출력"하는 구조다.
 *       그래서 문자열 끝까지 들어간 뒤 되돌아 나오면서 출력되므로
 *       결과적으로 역순이 된다. (출력을 재귀 호출 앞에 두면 정순이 된다.)
 *
 * 예) "abc" 를 넣으면
 *     reverse_print("abc") -> reverse_print("bc") -> reverse_print("c")
 *     -> reverse_print("")  여기서 종료, 되돌아 나오며 'c','b','a' 순으로 출력
 */
void reverse_print(const char *s)
{
    // 종료 조건: 문자열의 끝(널 문자 '\0')에 도달하면 더 진행하지 않는다.
    if (*s == '\0')
        return;

    // 재귀 호출: 포인터를 한 칸 앞으로 옮겨 나머지 문자열을 먼저 처리한다.
    reverse_print(s + 1);

    // 되돌아 나오면서 현재 문자를 출력한다(그래서 역순이 된다).
    putchar(*s);
}

/*
 * hanoi - 하노이의 탑 문제를 푼다.
 *
 * 문제: 기둥 from 에 쌓인 원반 n개를 기둥 to 로 옮긴다.
 *       규칙 1) 원반은 한 번에 하나씩만 옮긴다.
 *       규칙 2) 큰 원반을 작은 원반 위에 올릴 수 없다.
 *
 * 해법(3단계):
 *   1) 위쪽 n-1개를 보조 기둥(via)으로 옮긴다.
 *   2) 가장 큰 원반 1개를 목적지(to)로 옮긴다.
 *   3) 보조 기둥의 n-1개를 목적지(to)로 옮긴다.
 *
 * 총 이동 횟수는 2^n - 1 번이다. (원반 3개면 7번)
 *
 * 매개변수:
 *   n    - 옮길 원반의 개수
 *   from - 출발 기둥
 *   to   - 도착 기둥
 *   via  - 경유(보조) 기둥
 */
void hanoi(int n, char from, char to, char via)
{
    // 종료 조건: 옮길 원반이 없으면 할 일이 없다.
    if (n == 0)
        return;

    // 1단계: 맨 아래 원반을 뺀 나머지를 보조 기둥으로 옮긴다.
    //        이때 목적지였던 to 가 보조 기둥 역할을 한다.
    hanoi(n - 1, from, via, to);

    // 2단계: 가장 큰 원반 하나를 목적지로 옮긴다(실제 이동 출력).
    printf("원반 %d: %c -> %c\n", n, from, to);

    // 3단계: 보조 기둥에 있던 원반들을 목적지로 옮긴다.
    //        이번에는 출발지였던 from 이 보조 기둥 역할을 한다.
    hanoi(n - 1, via, to, from);
}

/*
 * main - 위에서 만든 재귀 함수들을 하나씩 호출해 결과를 확인한다.
 */
int main(void)
{
    printf("factorial(5)   = %lld\n", factorial(5));   // 5! = 120
    printf("sum_to(10)     = %d\n", sum_to(10));       // 1+2+...+10 = 55
    printf("fibonacci(10)  = %d\n", fibonacci(10));    // 0,1,1,2,3,5,8,13,21,34,55
    printf("gcd(48, 18)    = %d\n", gcd(48, 18));      // 48과 18의 최대공약수 = 6
    printf("power(2, 10)   = %lld\n", power(2, 10));   // 2^10 = 1024

    // "recursion" 을 거꾸로 출력하면 "noisrucer"
    printf("reverse_print  = ");
    reverse_print("recursion");
    putchar('\n');   // 줄바꿈 (reverse_print 는 줄바꿈을 하지 않으므로)

    // 원반 3개짜리 하노이의 탑: A 기둥에서 C 기둥으로, B를 경유해서 옮긴다.
    printf("hanoi(3):\n");
    hanoi(3, 'A', 'C', 'B');

    return 0;   // 프로그램이 정상 종료되었음을 운영체제에 알린다.
}
