#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x[11] = {0};
int tap[11] = {0,-10,-9,23,56,63,56,23,-9,-10,0};

int main(void)
{
    FILE *input_fptr;
    FILE *output_fptr;
    srand(time(NULL));
    input_fptr = fopen("updma_input.log", "w");
    output_fptr = fopen("updma_output_gold.log", "w");
    int lower_bound = -200;
    int upper_bound = 200;
    int range = upper_bound - lower_bound;
    for(int i=0;i<57600;i++){
        int random_number = rand() % range + lower_bound;
        printf("%08x\n",random_number);
        fprintf(input_fptr, "%08x\n",random_number);
        for(int j=9;j>=0;j--){
            x[j+1] = x[j];
        }
        x[0] = random_number;
        int k = 0;
        for (int j=0;j<11;j++){
            k+=x[j]*tap[j];
        }
        fprintf(output_fptr, "%08x\n",k);
    }

    fclose(input_fptr);
    fclose(output_fptr);
    return 0;
}

