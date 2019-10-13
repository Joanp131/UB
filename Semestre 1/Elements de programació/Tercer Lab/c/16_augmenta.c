/* Llegeix un nombre enter i a continuació llegeix tants enters i escriu tots els nombres que són més grans que el nombre inmediatament anterior llegit */
#include <stdio.h>

int main(void) {
    int len, i, j;

    printf("Quants nombres enters vols llegir?\n");
    scanf("%d", &len);

    int nums[len];

    printf("Escriu %d nombres enters:\n", len);
    for (i = 0; i < len; i++) {
        scanf("%d", &nums[i]);
        for (j = 0; j < i; j++) {
            if (nums[j] > nums[i]) {
                printf("%d, ", nums[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
