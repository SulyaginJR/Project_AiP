#include <stdio.h>
#define YES 1
#define NO 0
#define ARR 1000
#define N 10
#define N 3
#define K 4

int lr1(void)

{
    float P, A, B, C;

    printf("A=");
    scanf("%f", &A);
    printf("B=");
    scanf("%f", &B);
    printf("C=");
    scanf("%f", &C);

    P = A / ( B + C*C*C);
    printf("P=%f", P);

    return 0;
    system("pause");
}

int lr2(void)

{
    float s = 0, a;
    int n, i = 0, k = 1;
    printf("n=");
    scanf("%d", &n);
    while(i<n)
    {
        a = ( 3.0 + i ) / (( 1.0 + i ) * ( 2.0 + i ));
        s = s + a * k;
        k = -k;
        i += 1;
    }
    printf("s=%f",s);

    return 0;
    system("pause");
}

int lr3(void)

{
    int c;
    int flag = NO;
    int found = NO;
    int point =NO;
    int count = 0;

    while ((c = getchar()) != EOF)
    {
        if((c != ' ' || c != '\n' ||  c != ','))
        flag = YES;

        if (flag == YES)
        {
            if((c>='0' ) && (c <='9' ))
            found = YES;
            if(found == YES)
            {
                if(c == '.')
                {
                    point = YES;
                }
            }
            if(c != '0' && c != '1' && c != '2' && c != '3' && c != '4' &&
            c != '5' && c != '6' && c != '7' && c != '8' && c != '9' && c != '.')
            found = NO;
            if(point == YES && found == YES)
            count += 1;
        }

        point = NO;

        if (c == ' ' || c == '\n' ||  c == ',') 
        flag = NO;
    }
    return 0;
    system("pause");
}

int lr4(void)

{
    char x[ARR];
    int i = 0, j, k, m, flag = 0, xflag = 0;
    getchar();
    fgets(x, ARR, stdin);
    while(x[i])
    {
        if(x[i] != ' ' && flag == 0)
        {
            flag = 1;
            k = i;
        }
        if(flag == 1 && (x[i] == ' ' || x[i] == '.' || x[i] == '\n' || x[i] == ','))
        {
            for(j = k; j < i - 1; j++)
            {
                for(m = k + 1; m < i; m++)
                {
                    if(x[j] == x[m] && j != m)
                    {
                        xflag = 1;
                    }
                }
            }
            if(xflag == 0)
            {
                for(j = k; j < i; j++)
                    printf("%c",x[j]);
                printf(" ");
            }
            xflag = 0;
            flag = 0;
        }
        i++;
    }
    return 0;
    system("pause");
}

int lr5(void)

{
    int arr[N];
    int i;
    for (i = 0; i < N; i++) 
    {
        scanf("%d", &arr[i]);
    }

    int r = arr[1] / arr[0];

    for (i = 2; i < N; i++) 
    {
        if ((arr[i] / arr[i - 1]) != r) 
        {
            printf("The elements of the array do not form a geometric progression\n");
            return 0;
        }
    }

    printf("The elements of the array form a geometric progression\n");

    return 0;
    system("pause");
}

int lr6(void)

{
    int arr[N][K];
    int min = 0;
    int min_row = 0, min_col = 0;

    printf("Enter the array elements:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < K; j++) 
        {
            scanf("%d", &arr[i][j]);
            if ((i == 0 && j == 0) || arr[i][j] < min) 
            {
                min = arr[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    for (int j = 0; j < K; j++) 
    {
        arr[min_row][j] = 0;
    }

    for (int i = 0; i < N; i++) 
    {
        arr[i][min_col] = 0;
    }

    printf("New array:\n");
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < K; j++) 
        {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
    system("pause");
}

int maxLengthOfConsecutiveOnes(unsigned long R) {
    int maxLength = 0;
    int currentLength = 0;

    while (R) {
        if (R & 1) {
            currentLength++;
        } else {
            if (currentLength > maxLength) {
                maxLength = currentLength;
            }
            currentLength = 0;
        }
        R >>= 1; // Bitwise shift to the right by one digit
    }

    if (currentLength > maxLength) {
        maxLength = currentLength;
    }

    return maxLength;
}

int lr7(void) {
    unsigned long R;
    printf("Enter a long integer: ");
    scanf("%lu", &R);

    int maxConsecutiveOnes = maxLengthOfConsecutiveOnes(R);

    printf("The length of the longest series of units in the number %lu is equal to: %d\n", R, maxConsecutiveOnes);

    return 0;
    system("pause"); 
}