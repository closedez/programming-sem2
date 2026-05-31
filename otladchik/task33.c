#include <stdio.h>

#define SQR(x) ((x) * (x))

int main() {
    int y = 5;
    int z = SQR(y + 1);
    printf("z = %d\n", z); // 36
    return 0;
}