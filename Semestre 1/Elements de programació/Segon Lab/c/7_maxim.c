/* Càlcul del màxim de tres nombres reals usant com a molt dos if */
#include <stdio.h>

int main(void) {

    int i, len, sort = 1;

    printf("De quants nombres vols trobar el màxim?\n");
    scanf("%d", &len);

    float nums[len];
    
    for (i = 0; i < len; i++) {
        printf("Dona'm un nombre real: \n");
        scanf("%f", &nums[i]);
    }

    while (sort) {
        sort = 0;
        for (i = 0; i < len-1; i++) {
            float prev = nums[i];
            if (prev > nums[i+1]) {
                nums[i] = nums[i+1];
                nums[i+1] = prev;
                sort = 1;
            }
        }
    }

    printf("El màxim dels %d nombres és %f\n", len, nums[len-1]);
    
    return 0;
}
