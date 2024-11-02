#include <stdio.h>

void code();
void decode();

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("n/a");
    }

    if (argv[1][0] == '0') {
        code();
    } else if (argv[1][0] == '1') {
        decode();
    } else {
        printf("n/a");
    }

    return 0;
}

void code() {
    char sym = 0;
    int space = 0;
    int s = 0;
    int last = 0;

    while (1) {
        char temp = sym;
        sym = getchar();

        if (sym == '\n') {
            last = temp;
            break;
        }

        if (sym == ' ') {
            if (s > space && (s - 1 == space || space != 0)) {
                printf("%X ", temp);
            }
            ++space;
        } else {
            s++;
        }
    }

    if (s - space > 1 || s - space < 1 || space == 0) {
        printf("n/a");
    } else if (s - space == 1 && space != 0) {
        printf("%X", last);
    }
}

void decode() {
    unsigned int sym = 0;
    unsigned int last = 0;
    int s = 0;
    int space = 0;

    while (1) {
        if (scanf("%X", &sym) != 1) {
            break;
        }
        char nextChar = getchar();
        last = sym;
        s++;
        if (nextChar == '\n' || feof(stdin)) {
            break;
        } else if (nextChar == ' ') {
            ++space;
            printf("%c ", last);
        } else if (nextChar != ' ' && nextChar != '\n') {
            printf("%c ", last);
        }
    }

    if (s - space <= 1 && space == 0) {
        printf("n/a");
    } else {
        printf("%c", last);
    }
}
