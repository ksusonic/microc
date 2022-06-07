#include "stdio.h"

unsigned long oct_to_dec(unsigned long number) {
    unsigned long int num_new = 0, stepen = 1;
    while (number > 0) {
        unsigned long int last_dig = (number % 10) * stepen;
        num_new = num_new + last_dig;
        number /= 10;
        stepen *= 8;
    }
    number = num_new;
    return number;
}

unsigned long int oct_to_binary(unsigned long int number) {
    number = oct_to_dec(number);
    unsigned long int res=0, d=1;
    while(number) {
        res += (number%2) * d;
        number /= 2;
        d *= 10;
    }
    return res;
}

void dec_to_hex(int number, char code[5]) {
    number = oct_to_dec(number);
    for (int i = 4; i >= 0; i--) {
        int val = (number % 16);

        char c = val <= 9 ? val + '0' : (val - 10) + 'A';
        code[i] = c;
        number /= 16;
    }
}

char get_char(int number) {
    char res = number + '0';
    return res;
}

int get_int(char number) {
    return number - '0';
}

void long_to_char(unsigned long int number, char input_string[7]) {
    int j = 0;
    int k = 0;
    char buffer_char[7];
    if (number == 0) {
        input_string[0] = '0';
        input_string[1] = '\0';
    } else {
        while (number > 0) {
            int num = number % 10;
            buffer_char[j] = get_char(num);
            number = number / 10;
            j++;
        }

        for (k = j - 1; k >= 0; k--)
            input_string[j - k - 1] = buffer_char[k];

        input_string[j] = '\0';
    }
}

int main() {
    char c[5];
    dec_to_hex(12346, c);
    printf(c);
}