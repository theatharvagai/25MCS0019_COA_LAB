#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 52

void serialGame() {
    int deck[N], p1[N / 2], p2[N / 2];
    srand(time(NULL));

    for (int i = 0; i < N; i++) deck[i] = i + 1;

    for (int i = 0; i < N; i++) {
        int j = rand() % N;
        int t = deck[i];
        deck[i] = deck[j];
        deck[j] = t;
    }

    for (int i = 0; i < N / 2; i++) {
        p1[i] = deck[i];
        p2[i] = deck[i + N / 2];
    }

    printf("\n=== Serial Card Game ===\n");
    printf("Player 1: "); for (int i = 0; i < N / 2; i++) printf("%d ", p1[i]);
    printf("\nPlayer 2: "); for (int i = 0; i < N / 2; i++) printf("%d ", p2[i]);
    printf("\n=== Serial Game Complete ===\n");
}

void parallelGame() {
    int deck[N], p1[N / 2], p2[N / 2];
    srand(time(NULL));

    for (int i = 0; i < N; i++) deck[i] = i + 1;

#pragma omp parallel
    {
#pragma omp single
        printf("\n=== Parallel Card Game ===\n");

#pragma omp for
        for (int i = 0; i < N; i++) {
            int j = rand() % N;
            int t = deck[i];
            deck[i] = deck[j];
            deck[j] = t;
        }

#pragma omp sections
        {
#pragma omp section
            for (int i = 0; i < N / 2; i++) p1[i] = deck[i];

#pragma omp section
            for (int i = 0; i < N / 2; i++) p2[i] = deck[i + N / 2];
        }
    }

    printf("Player 1: "); for (int i = 0; i < N / 2; i++) printf("%d ", p1[i]);
    printf("\nPlayer 2: "); for (int i = 0; i < N / 2; i++) printf("%d ", p2[i]);
    printf("\n=== Parallel Game Complete ===\n");
}
