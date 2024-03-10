#include <stdio.h>

void findCombinations(int score, int td2pt, int tdFg, int td, int fg, int safety, int index) {
    int points[] = {8, 7, 6, 3, 2};
    if (score == 0) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td2pt, tdFg, td, fg, safety);
        return;
    }
    if (score < 0 || index == 5) { /
        return;
    }

    switch (index) {
        case 0: findCombinations(score - points[index], td2pt + 1, tdFg, td, fg, safety, index); break;
        case 1: findCombinations(score - points[index], td2pt, tdFg + 1, td, fg, safety, index); break;
        case 2: findCombinations(score - points[index], td2pt, tdFg, td + 1, fg, safety, index); break;
        case 3: findCombinations(score - points[index], td2pt, tdFg, td, fg + 1, safety, index); break;
        case 4: findCombinations(score - points[index], td2pt, tdFg, td, fg, safety + 1, index); break;
    }
    findCombinations(score, td2pt, tdFg, td, fg, safety, index + 1);
}

int main() {
    int score;
    printf("Enter 0 or 1 to STOP\n");
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        if (score > 1) {
            printf("Possible combinations of scoring plays:\n");
            findCombinations(score, 0, 0, 0, 0, 0, 0);
        }
    } while (score > 1);

    return 0;
}


