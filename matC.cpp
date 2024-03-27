#include<stdio.h>

void PutPar(int s[][6], int i, int j, int* p) {
    if (i == j) {
        printf("%d", p[i]);
    } else {
        printf("(");
        PutPar(s, i, s[i][j], p);
        PutPar(s, s[i][j] + 1, j, p);
        printf(")");
    }
}

int main() {
    int p[100], no, n, m[6][6], s[6][6], j, k, i, q;

    printf("Enter the number of matrices: ");
    scanf("%d", &no);

    printf("Enter dimensions of matrices (from 0 to %d):\n", no);
    for (int i = 0; i <= no; i++) {
        scanf("%d", &p[i]);
    }

    printf("Array is:\n");
    for (i = 0; i <= no; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");

    n = no;
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = 9999999; // Set initial value to a large number
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization: ");
    PutPar(s, 1, n, p);
    printf("\n");

    return 0;
}

