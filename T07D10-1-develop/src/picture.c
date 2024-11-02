#include <stdio.h>
#include <stdlib.h>
#define N 15
#define M 13

void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);
void make_frame(int **picture, int n, int m, int *frame_w, int *frame_h);

int main() {
    int *picture_data = (int *)malloc(sizeof(int) * N * M);
    int **picture = (int **)malloc(sizeof(int *) * N);

    transform(picture_data, picture, N, M);
    make_picture(picture, N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", picture[i][j]);
        }
        printf("\n");
    }
    free(picture_data);
    free(picture);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    reset_picture(picture, n, m);

    for (int i = 0; i < 6; i++) {
        for (int x = 0; x < 5; x++) {
            picture[i + 1][x + 7] = sun_data[i][x];
        }
    }
    int size = 4;
    for (int x = 0; x < size; x++) {
        int y = 0;
        if (x == 0 || x == 3) {
            size = 2;
            y = 1;
        }
        for (int i = 0; i < size; i++) {
            picture[2 + x][i + 2 + y] = tree_foliage[i];
        }
        size = 4;
    }
    for (int x = 0; x < 5; x++) {
        size = 2;
        int y = 0;
        if (x == 4) {
            size = 4;
            y = 1;
        }
        for (int i = 0; i < size; i++) {
            picture[x + 6][i + 3 - y] = tree_trunk[i];
        }
    }
    make_frame(picture, n, m, frame_w, frame_h);
}

void make_frame(int **picture, int n, int m, int *frame_w, int *frame_h) {
    for (int i = 0; i < m; i++) {
        picture[0][i] = frame_w[i];
        picture[n - 1][i] = frame_w[i];
    }
    for (int i = 1; i < n - 1; i++) {
        picture[i][0] = 1;
        picture[i][m - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        picture[n / 2][i] = frame_w[i];
    }
    for (int i = 1; i < n - 1; i++) {
        picture[i][m / 2] = frame_h[i];
    }
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}