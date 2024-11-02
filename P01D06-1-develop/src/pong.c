#include <stdio.h>

#define HEIGHT 25
#define WIDTH 80
#define CENTER_X ((WIDTH) / 2)
#define CENTER_Y ((HEIGHT + 1) / 2)
#define RACKET_X 3
#define RACKET2_X (WIDTH - 4)
#define WIN_SCORE 21
#define RACKET_SYMBOL '|'
#define BORDER_Y_SYMBOL '|'
#define CENTER_Y_SYMBOL ':'
#define BORDER_X_SYMBOL '-'
#define SPACE_SYMBOL ' '
#define BALL_SYMBOL 'o'

void clrscr(void);
void fieldRender(int racket1Y, int racket2Y, int ballX, int ballY);
int checkScore(int score1, int score2);
void clearBuffer();

int main(void) {
    // racket parameters
    int racket1Y = 3;
    int racket2Y = HEIGHT - 4;

    // ball parameters
    int ballX = CENTER_X + 1;
    int ballY = CENTER_Y;
    int vectorX = 1;
    int vectorY = -1;

    // score
    int score1 = 0;
    int score2 = 0;

    while (1) {
        clrscr();
        printf("                      Игрок 1:    %d     -     %d    :Игрок 2\n", score1, score2);
        fieldRender(racket1Y, racket2Y, ballX, ballY);
        printf("Первый игрок (a - вверх, z - вниз): ");
        char temp;
        scanf("%c", &temp);
        clearBuffer();
        switch (temp) {
            case 'a':
                ((racket1Y - 2) != 0) ? (racket1Y -= 1) : racket1Y;
                break;
            case 'z':
                ((racket1Y + 2) != HEIGHT - 1) ? (racket1Y += 1) : racket1Y;
                break;
            case ' ':
                break;
        }
        printf("Второй игрок (k - вверх, m - вниз): ");
        char temp2;
        scanf("%c", &temp2);
        clearBuffer();
        switch (temp2) {
            case 'k':
                ((racket2Y - 2) != 0) ? (racket2Y -= 1) : racket2Y;
                break;
            case 'm':
                ((racket2Y + 2) != HEIGHT - 1) ? (racket2Y += 1) : racket2Y;
                break;
            case ' ':
                break;
        }
        if (ballX == RACKET_X + 1) {
            if (ballY == racket1Y) {
                vectorY = 0;
                vectorX = vectorX * -1;
            }
            if (ballY == racket1Y + 1) {
                vectorY = 1;
                vectorX = vectorX * -1;
            }
            if (ballY == racket1Y - 1) {
                vectorY = -1;
                vectorX = vectorX * -1;
            }
        }
        if (ballX == RACKET2_X - 1) {
            if (ballY == racket2Y) {
                vectorY = 0;
                vectorX = vectorX * -1;
            }
            if (ballY == racket2Y + 1) {
                vectorY = 1;
                vectorX = vectorX * -1;
            }
            if (ballY == racket2Y - 1) {
                vectorY = -1;
                vectorX = vectorX * -1;
            }
        }
        if (ballY == 1 || ballY == HEIGHT - 2) {
            vectorY = vectorY * -1;
        }
        if (ballX == 1) {
            score2 = score2 + 1;
            ballX = CENTER_X;
            ballY = CENTER_Y;
            vectorY = -1;
        } else if (ballX == WIDTH - 2) {
            score1 = score1 + 1;
            ballX = CENTER_X;
            ballY = CENTER_Y;
            vectorY = 1;
        }

        if (checkScore(score1, score2) == 1) {
            printf("Player 1 WIN\n");
            break;
        } else if (checkScore(score1, score2) == 2) {
            printf("Player 2 WIN\n");
            break;
        }
        ballX = ballX + vectorX;
        ballY = ballY + vectorY;
    }
}

void clrscr(void) { printf("\33[0d\33[2J"); }
void fieldRender(int racket1Y, int racket2Y, int ballX, int ballY) {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (y == 0 || y == HEIGHT - 1) {     // first and last line
                if (x == 0 || x == WIDTH - 1) {  // first, and last cell
                    printf("%c", BORDER_Y_SYMBOL);
                } else {
                    printf("%c", BORDER_X_SYMBOL);
                }
            } else if (x == 0 || x == WIDTH - 1) {
                printf("%c", BORDER_Y_SYMBOL);
            } else {
                if (x == CENTER_X) {
                    printf("%c", CENTER_Y_SYMBOL);
                } else if (x == RACKET_X &&
                           (y == racket1Y || y == racket1Y + 1 || y == racket1Y - 1)) {  // print racket1
                    printf("%c", RACKET_SYMBOL);
                } else if (x == RACKET2_X &&
                           (y == racket2Y || y == racket2Y + 1 || y == racket2Y - 1)) {  // print racket2
                    printf("%c", RACKET_SYMBOL);
                } else if (x == ballX && y == ballY) {  // print ball
                    printf("%c", BALL_SYMBOL);
                } else {
                    printf("%c", SPACE_SYMBOL);
                }
            }
        }
        printf("\n");
    }
}
int checkScore(int score1, int score2) {
    if (score1 == WIN_SCORE) {
        return 1;
    }

    if (score2 == WIN_SCORE) {
        return 2;
    }
    return 0;
}
void clearBuffer() {
    while (getchar() != '\n')
        ;
}
