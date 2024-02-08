////Задача 1. Китайская Теорема об Остатках
//Задача 1. Китайская Теорема об Остатках
//X = E (n, i = 0) M
//для нахождения обратного по модулю, юзать расширенный алг Евк
////Задача 2. Арифметика по модулю
////бин поиск

////Задача 1. Китайская Теорема об Остатках
//#include <stdio.h>
//int gcd(int a, int b){ // рекурсивно вычислить НОД двух чисел
//    if (b == 0) {
//        return a;
//    }
//    return gcd(b, a % b);
//}
//
//// функция для определения возможного решения
//int check(int b[], int n){
//    for (int x = 0; x < n; x++){
//        for (int y = x + 1; y < n; y++){
//            if (gcd(b[x], b[y]) != 1) {
//                return 1;
//            }
//        }
//    }
//    return 0;
//}
//
//// Китайская теорема об остатках
//int evaluate(int *a, int *b, int n){
//    int Minv[n];
//    int q, r, r1, r2, t, t1, t2;
//    int total = 1;
//    for (int k = 0; k < n; k++) {
//        total *= b[k];
//    }
//    for (int k = 0; k < n; k++){
//        r1 = b[k];
//        r2 = total / b[k];
//        t1 = 0;
//        t2 = 1;
//        while (r2 > 0){
//            q = r1 / r2;
//            r = r1 - q * r2;
//            r1 = r2;
//            r2 = r;
//
//            t = t1 - q * t2;
//            t1 = t2;
//            t2 = t;
//        }
//        if (r1 == 1) {
//            Minv[k] = t1;
//        }
//        if (Minv[k] < 0) {
//            Minv[k] = Minv[k] + b[k];
//        }
//    }
//    int x = 0;
//    for (int k = 0; k < n; k++) {
//        x += (a[k] * total * Minv[k]) / b[k];
//    }
//    return x;
//}
//// основная функция
//int main(){
//    int n = 2;    // количество уравнений
//    int a[2], b[2];
//    for (int i = 0; i < n-1; i++)
//        scanf("%d\n", &a[i]);
//    printf("next:\n");
//    for (int i = 0; i < n; i++)
//        scanf("%d\n", &b[i]);
//
//    if (!check(b, n)) {
//        printf("x = %lld\n", evaluate(a, b, n));
//    }
//    else {
//        printf("The given equations has no solutions.\n");
//    }
//    return 0;
//}

//#include <stdio.h>
//#define max 1000001
//typedef long long int64;
//int64 M[max], A[max];
//
//int evklid(int a, int b){
//    int p=1, q=0, r=0, s=1, x, y;
//    while (a && b) {
//        if (a>=b) {
//            a = a - b;
//            p = p - r;
//            q = q - s;
//        } else {
//            b = b - a;
//            r = r - p;
//            s = s - q;
//        }
//    }
//    if (a) {
//        x = p;
//        y = q;
//    }else {
//        x = r;
//        y = s;
//    }
//    printf("koef:%d %d\n", x, y);
//    return x;
//}
//
////X = sum (P/Mi) * (inv(P/Mi) * Ai  mod Mi)
//int64 formula(int64 *M, int64 *A, int64 P, int64 k){
//    int64 res = 0;
//    for(int i = 0; i < k; i++)
//        res += (P/M[i]) % M[i]   *   ( (evklid(A[i], M[i]) + M[i]) % M[i] * A[i] % M[i] );
//    return res;
//}
//
//int main(){
//    int k;
//    int64 P = 1;
//    scanf("%d", &k);
//    for(int i = 0; i < k; i++) {
//        scanf("%d", &M[i]);
//        P *= M[i];
//    }
//    for(int i = 0; i < k; i++)
//        scanf("%d", &A[i]);
//    printf("\n== %lld ==\n", formula(M, A, P, k) % P); //ВЫВОД
////    printf("otvet:%lld", ((evklid(100, 45) + 100) % 100));
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdint.h>
//int64_t gcd(int64_t a, int64_t b){
//    if(b == 0){
//        return a;
//    } else {
//        return gcd (b, a % b);
//    }
//}
//
//int64_t modInv(int64_t a, int64_t modulo){
//    int64_t m0 = modulo, t, q;
//    int64_t x0 = 0, x1 = 1;
//    if(modulo == 1){
//        return 0;
//    }
//    while(a > 1){
//        q = a / modulo;
//        t = modulo;
//        modulo = a % modulo, a = t;
//        t = x0;
//        x0 = x1 - q * x0;
//        x1 = t;
//    }
//    if(x1 < 0){
//        x1 += m0;
//    }
//    return x1;
//}
//
//int64_t crt(int64_t *mods, int64_t *remainders, int64_t n){
//    int64_t prod = 1;
//    for(int64_t i = 0; i < n; i++){
//        prod *= mods[i];
//    }
//    int64_t result = 0;
//    for (int64_t i = 0; i < n; ++i) {
//        int64_t p = prod / mods[i];
//        result += remainders[i] * modInv(p, mods[i]) * p;
//    }
//    return result % prod;
//}
//
//int main(){
//    int64_t n;
//    scanf("%lld", &n);
//    int64_t *mods = (int64_t *)malloc(sizeof (int64_t) * n);
//    int64_t *remainders = (int64_t*)malloc(sizeof(int64_t) * n);
//    for (int64_t i = 0; i < n; ++i) {
//        scanf("%lld", &mods[i]);
//    }
//    for (int64_t i = 0; i < n; ++i) {
//        scanf("%lld", &remainders[i]);
//    }
//    int64_t result = crt(mods, remainders, n);
//    printf("%lld\n", result);
//    free(mods);
//}

////Задача 1. Китайская Теорема об Остатках
//#include <stdio.h>
//#include <stdlib.h>
//typedef long long int64;
//
//int64 gcd_ext(int64 a, int64 b, int64* x, int64* y) {
//    if (b == 0) {
//        *x = 1;
//        *y = 0;
//        return a;
//    }
//    int64 x1, y1;
//    int64 d = gcd_ext(b, a % b, &x1, &y1);
//    *x = y1;
//    *y = x1 - y1 * (a / b);
//    return d;
//}
//int64 inverse_modulo(int64 a, int64 m) {
//    int64 x, y;
//    int64 d = gcd_ext(a, m, &x, &y);
//    int64 inverse = ((x % m) + m) % m;
//    return inverse;
//
//}
//////X = sum (P/Mi) * (inv(P/Mi) * Ai  mod Mi)
//int64 crt(int64 *mods, int64 *remainders, int64 k){ //mods - модули, remainders - остатки
//    int64 prod = 1;
//    for(int64 i = 0; i < k; i++) //произведение всех модулей
//        prod *= mods[i];
//    int64 result = 0;
//    for (int64 i = 0; i < k; ++i) {
//        int64 p = prod / mods[i];
//        result += remainders[i] * inverse_modulo(p, mods[i]) * p;
////        result += remainders[i] * modInv(p, mods[i]) * p;
//    }
//    return result % prod;
//}
//
//int main(){
//    int64 k; //целое положительное число 𝑘 — количество модулей
//    scanf("%lld", &k);
//    int64 *M = (int64 *)malloc(sizeof (int64) * k); //𝑘 целых чисел 𝑀1, 𝑀2, . . ., 𝑀𝑘 — модули.
//    int64 *A = (int64*)malloc(sizeof(int64) * k); //𝑘 целых чисел 𝐴1, 𝐴2, . . ., 𝐴𝑘 — остатки от деления
//    for (int64 i = 0; i < k; ++i)
//        scanf("%lld", &M[i]);
//    for (int64 i = 0; i < k; ++i)
//        scanf("%lld", &A[i]);
//    int64 res = crt(M, A, k);
//    printf("%lld\n", res);
//}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

typedef long long int64;

void add(int64 a, const int64 b, const int64 m) {
    a += b;
    if (a >= m)
        a -= m;
}

int mult(const int a, const int b, const int m) {
    return (a * b) % m;
}

int64 Euclid(int64 a, int64 b, int64 x, int64 y) {
    if (!b) {
        x = (a < 0 ? -1 : 1);
        y = 0;
        return a * x;
    }
    int64 q = a / b;
    int64 r = a % b;
    int64 d = Euclid(b, r, y, x);
    y -= q * x;
    return d;
}

int n;
int mod[32];
int arr[32];

int base[32];

int main() {
    scanf("%d", &n);
    assert(n > 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", mod + i);
        assert(mod[i] >= 2 && mod[i] <= 1000000000);
    }
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    int64 prod = 1;
    for (int i = 0; i < n; i++)
        prod *= mod[i];
    assert(prod > 1 && prod <= 1000LL * 1000 * 1000 * 1000 * 1000 * 1000);

    for (int i = 0; i < n; i++) {
        int64 q = prod / mod[i];
        int64 x, y;
        assert(Euclid(q, mod[i], x, y) == 1);
        if (x < 0)
            x += mod[i];
        base[i] = x;
    }

    int64 res = 0;
    for (int i = 0; i < n; i++)
        add(res, prod / mod[i] * mult(base[i], arr[i], mod[i]), prod);

    printf("%I64d\n", res);
    return 0;
}