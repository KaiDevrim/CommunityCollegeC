/*
    Complete this program by writing a nested for loop that sums the columns
    in the data array and puts those sums into the column_sums array.
    You do not have to write the entire program.
    You only have to write the for loop.
*/
#include <stdio.h>

int main(void)
{
    int data[3][4] = {
        {1, 0, 6, 6},
        {7, 8, 7, 1},
        {5, 7, 1, 1},
    };

    int column_sums[4] = {0, 0, 0, 0};
    for (int rows = 0; rows < 3; rows++)
    {
        for (int columns = 0; columns < 4; columns++)
        {
            column_sums[columns] = column_sums[columns] + data[rows][columns];
        }
    }

    printf("Column sums: ");
    for (int index = 0; index < 4; index++)
    {
        printf("%d ", column_sums[index]);
    }
    printf("\n");
    return 0;
}
