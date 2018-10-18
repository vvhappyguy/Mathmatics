#include <stdio.h>
#include <malloc.h>

/*
 Global variables
 num for counting matrixes
 array for storage all inited matrixes
*/
short num = 0;
struct matrix *array;

// Update memory for add new matrix
void updMemory()
{
    array = realloc(array, 24 * (num + 1));
}

/*  Structure of matrix */
struct matrix
{
    short number;
    int rows;
    int columns;
    float **a;
};

/* Factrory-method for struct matrix */
struct matrix init()
{
    struct matrix matr;
    int i, j;

    matr.number = num;
    matr.columns = 0;
    matr.rows = 0;
    num++;
    printf("Please, enter count of columns and rows #%d \n", matr.number);
    printf("->\n");
    scanf("%d", &matr.rows);
    scanf("%d", &matr.columns);
    if (matr.rows < 1 || matr.columns < 1)
    {
        printf("!!! Incorrect input\n");
        printf("!!! Start Again\n");
        printf("\n-------------------------------------------------\n");
        struct matrix zero;
        zero.columns = 0;
        zero.number = 0;
        zero.number = -1;
        return zero;
    }
    printf("->");
    printf("Enter value of matrix's element (float) №%d  \n", matr.number);

    matr.a = (float **)malloc(matr.rows * sizeof(float *));
    for (i = 0; i < matr.rows; i++)
    {
        matr.a[i] = (float *)malloc(matr.columns * sizeof(float));
        for (j = 0; j < matr.columns; j++)
        {
            printf("m[%d][%d] = ", i, j);
            scanf("%f", &matr.a[i][j]);
        }
    }
    printf("\n-------------------------------------------------\n");
    return matr;
}

void print_matrix();

// Sum of two matrixes
struct matrix add(struct matrix matr1, struct matrix matr2, short k)
{
    if (matr1.rows != matr2.rows || matr1.columns != matr2.columns || (k != 0 && k != 1))
    {
        printf("\n!!! Can't sum matrixes\n");
        printf("!!! Different size\n");
        struct matrix zero;
        zero.columns = 0;
        zero.rows = 0;
        zero.number = -1;
        return zero;
    }
    else
    {
        int i, j;
        struct matrix add;
        add.number = num;
        num++;
        add.rows = matr1.rows;
        add.columns = matr1.columns;
        add.a = (float **)malloc(matr1.rows * sizeof(float *));
        for (i = 0; i < matr1.rows; i++)
        {
            add.a[i] = (float *)malloc(add.columns * sizeof(float));
            for (j = 0; j < add.columns; j++)
            {
                add.a[i][j] = 0.1;
            }
        }
        if (k == 0)
        {
            printf("Sum of №%d + №%d matrixes", matr1.number, matr2.number);
            for (i = 0; i < add.rows; i++)
            {
                for (j = 0; j < add.columns; j++)
                {
                    add.a[i][j] = matr1.a[i][j] + matr2.a[i][j];
                }
                printf("\n");
            }
        }
        else if (k == 1)
        {
            printf("Deduct of №%d - №%d", matr2.number, matr1.number);
            for (i = 0; i < add.rows; i++)
            {
                for (j = 0; j < add.columns; j++)
                {
                    add.a[i][j] = matr1.a[i][j] - matr2.a[i][j];
                }
                printf("\n");
            }
        }

        return add;
    }
}

// Power of two matrixes
struct matrix power(struct matrix matr1, struct matrix matr2)
{
    if (matr1.columns != matr2.rows)
    {
        printf("\n!!! Can't product matrixes\n");
        printf("!!! Bad sizes\n");
        struct matrix zero;
        zero.columns = 0;
        zero.rows = 0;
        zero.number = -1;
        return zero;
    }
    else
    {
        int i, j, k;
        struct matrix power;
        power.number = num;
        num++;
        power.rows = matr1.rows;
        power.columns = matr2.columns;
        //printf(" %d %d %d %d", matr1.rows, matr2.rows, matr1.columns, matr2.columns);
        power.a = (float **)malloc(matr1.rows * sizeof(float *));
        for (i = 0; i < matr1.rows; i++)
        {
            power.a[i] = (float *)malloc(matr2.columns * sizeof(float));
            for (j = 0; j < power.columns; j++)
            {
                power.a[i][j] = 0;
            }
        }

        for (i = 0; i < matr1.rows; i++)
        {
            for (j = 0; j < matr2.columns; j++)
            {
                power.a[i][j] = 0;
                for (k = 0; k < matr2.rows; k++)
                {
                    power.a[i][j] += (matr1.a[i][k] * matr2.a[k][j]);
                }
            }
        }

        return power;
    }
}

// Take matrix to n (pow(n)). it's like matrix^n
struct matrix matrixPowN(struct matrix matr)
{
    int o;
    printf("Degree of pow matrix^n. Enter n. %d\n", matr.number);
    scanf("%d", &o);
    if (matr.rows != matr.columns || o < 0)
    {
        printf("\n!!! Can't pow matrix\n");
        printf("!!! Matrix must be square\n");
        struct matrix zero;
        zero.columns = 0;
        zero.rows = 0;
        zero.number = -1;
        return zero;
    }
    else
    {
        int i, j, l;
        //Матрица, которая будет return'om
        struct matrix pown;
        pown.number = num;
        num++;
        pown.rows = matr.rows;
        pown.columns = matr.columns;
        pown.a = (float **)malloc(matr.rows * sizeof(float *));
        for (i = 0; i < matr.rows; i++)
        {
            pown.a[i] = (float *)malloc(matr.columns * sizeof(float));
            for (j = 0; j < matr.columns; j++)
            {
                if (i == j)
                {
                    pown.a[i][j] = 1;
                }
                else
                {
                    pown.a[i][j] = 0;
                }
            }
        }

        if (o == 1)
        {
            return matr;
        }

        for (l = 2; l <= o; l++)
        {
            if (l == 2)
            {
                num--;
                pown = power(matr, matr);
            }
            else
            {
                num--;
                pown = power(pown, matr);
            }
        }
        return pown;
    }
}

// Transporation of matrix 
struct matrix transp(struct matrix matr)
{
    int i, j;
    struct matrix tran;
    tran.number = num;
    num++;
    tran.rows = matr.columns;
    tran.columns = matr.rows;
    tran.a = (float **)malloc(tran.rows * sizeof(float *));
    for (i = 0; i < tran.rows; i++)
    {
        tran.a[i] = (float *)malloc(tran.columns * sizeof(float));
        for (j = 0; j < tran.columns; j++)
        {
            tran.a[i][j] = matr.a[j][i];
        }
    }
    return tran;
}

// Main func)
int main(int argc, char *argv[])
{
    char q;
    printf("Press \'c\' to start or another for exit!\n");
    scanf(" %c", &q);
    while (q == 'c')
    {
        int count, state = 0;
        int i, a1, a2;
        printf("Welcome to matrix Calculator by Dyakin Ivan!!!\n");
        printf("----------------------------------------\n");
        if (num == 0)
        {
            printf("Enter count of matrixes which you want to init:\n");
            scanf(" %d", &count);

            for (i = 0; i < count; i++)
            {
                updMemory();
                array[i] = init();
            }

            for (i = 0; i < num; i++)
            {
                print_matrix(array[i]);
            }
        }
        else
        {
            for (i = 0; i < num; i++)
            {
                print_matrix(array[i]);
            }
        }

        printf("You can:\n0.Init Matrix\n1. Sum two\n2. Deduct two\n3. Product two\n4. Transporation\n5. Pow matrix to n degree\nChoose one of numbers.\n->\n");
        scanf(" %d", &state);
        switch (state)
        {
        case 0:
        {
            updMemory();
            array[num] = init();
            break;
        }
        case 1:
        {
            printf("Choose matrixes: ");
            scanf(" %ud", &a1);
            scanf(" %ud", &a2);
            printf("\n");
            updMemory();
            array[num] = add(array[a1], array[a2], 0);

            print_matrix(array[a1]);
            print_matrix(array[a2]);
            print_matrix(array[num - 1]);

            break;
        }
        case 2:
        {
            printf("Choose matrixes: ");
            scanf(" %ud", &a1);
            scanf(" %ud", &a2);
            printf("\n");
            updMemory();
            array[num] = add(array[a1], array[a2], 1);

            print_matrix(array[a1]);
            print_matrix(array[a2]);
            print_matrix(array[num - 1]);
            break;
        }
        case 3:
        {
            printf("Choose matrixes: ");
            scanf(" %ud", &a1);
            scanf(" %ud", &a2);
            printf("\n");
            updMemory();
            array[num] = power(array[a1], array[a2]);

            print_matrix(array[a1]);
            print_matrix(array[a2]);
            print_matrix(array[num - 1]);
            break;
        }
        case 4:
        {
            printf("Choose matrixes: ");
            scanf(" %ud", &a1);
            printf("\n");
            updMemory();
            array[num] = transp(array[a1]);

            print_matrix(array[a1]);
            print_matrix(array[num - 1]);
            break;
        }
        case 5:
        {
            printf("Choose matrixes: ");
            scanf(" %ud", &a1);
            printf("\n");
            updMemory();
            array[num] = matrixPowN(array[a1]);

            print_matrix(array[a1]);
            print_matrix(array[num - 1]);
            break;
        }
        default:
            printf("Incorrent enter. Try Again.");
        }

        printf("Press \'c\' to start or q for exit!\n");
        scanf(" %c", &q);
    }
    int i, state;
    //printf("\n\t%d",num);
    for(i = 0; i < num; i++){
        for(state = 0; state < array[i].columns;state++){
            free(array[i].a[state]);
        }
        free(array[i].a);
    }
    return 0;
}

// Print matrix-method
void print_matrix(struct matrix matr)
{
    int i, j;
    float **a = matr.a;
    printf("@\nPrint Matrix №%d\n", matr.number);
    for (i = 0; i < matr.rows; i++)
    {
        for (j = 0; j < matr.columns; j++)
        {
            printf("%3.2f ", a[i][j]);
        }
        printf("\n");
    }
    printf("@\n");
}
