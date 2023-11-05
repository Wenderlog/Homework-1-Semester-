#include <stdio.h>

void ToBinary(int num, char binary[]) {
    int mask = 1 << 31;
    int i = 0;
    for (i = 0; i < 32; i++) {
        if (num & mask) {
            binary[i] ='1';
        }else{
            binary[i] = '0';
        }
        num <<= 1;
    }
    binary[32] = '\0';
}

int binaryToDec(char binary[]) {
    int dec = 0;
    int i = 0;
    for (i = 0; i < 32; i++) {
        dec <<= 1;
        if (binary[i] == '1') {
            dec |= 1;
        }
    }
    return dec;
}

int main() {
    int num1 = 0;
    int num2 = 0;
    char binary[33] = { ' ' };
    int binary2[33] = { 0 };

    scanf("%d", &num1);
    scanf("%d", &num2);

    ToBinary(num1, binary);
    ToBinary(num2, binary2);

    printf("Двоичное представление 1 числа %s \n", binary);
    printf("Двоичное представление 2 числа %s \n", binary2);

    int sum = num1 + num2;
    char binarySum[33] = { ' ' };
    ToBinary(sum, binarySum);

    printf("Сумма в двоичном представлении %s \n", binarySum);
    printf("Сумма в десятичном представлении %d \n", sum);
}
