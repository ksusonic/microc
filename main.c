#include <stdio.h>

int dec_to_binary(int num) {
    int res = 0, d = 1;
    while (num) {
        res += (num % 2) * d;
        num = num / 2;
        d = d * 10;
    }
    return res;
}

int oct_to_dec(int number) {
    int result = 0, stepen = 1;
    while (number > 0) {
        result += (number % 10) * stepen;
        number /= 10;
        stepen *= 8;
    }
    return result;
}

char *to_ascii(int num, char word[5]) {
    for (int i = 0; i < 5; i++) {
        word[i] += num % 10;
        num /= 10;
    }
    return word;
}


int main() {
    char word[5] = "00000";
    printf("%s", to_ascii(12345, word));
    return 0;
}
