#include <stdio.h>

float horner(float *p, int n, float x) {
    if (n == 0) {
        return p[0];
    } else {
        return p[0] + x * horner(&p[1], n - 1, x);
    }
}

float horner(float *p, int n, float x) {
    return hornerRec(p, 0, n, x);
}

float hornerRec(float *p, int i, int n, float x) {
    if (i == n) {
        return p[i];
    } else {
        return p[i] + x * hornerRec(p, i + 1, n, x);
    }
}

int main() {
    return 0;
}