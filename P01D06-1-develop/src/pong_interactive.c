#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

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

void fieldRender(int racket1Y, int racket2Y, int ballX, int ballY);
int checkScore(int score1, int score2);

int main () {
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
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
   // keypad(stdscr, TRUE);

    while (1) {

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


        clear();
        mvhline(0,0, BORDER_X_SYMBOL, WIDTH);
        mvhline(HEIGHT-1,0, BORDER_X_SYMBOL, WIDTH);
        mvvline(0,0,BORDER_Y_SYMBOL, HEIGHT);
        mvvline(0,WIDTH,BORDER_Y_SYMBOL, HEIGHT);
        mvvline(3,3,RACKET_SYMBOL, 3);
        mvvline(HEIGHT - 5,WIDTH -3,RACKET_SYMBOL, 3);
        mvaddch(ballY, ballX, BALL_SYMBOL);

        getch();
        refresh();
        usleep(50000);
        
    
    


    } 
    endwin();  

    return 0;
}

    

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
