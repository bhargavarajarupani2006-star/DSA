#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int m, n;
    char grid[MAX][MAX];
    char word[MAX];
    char searchWord[6];  

    
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    
    printf("Enter the grid (uppercase letters only):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf(" %c", &grid[i][j]);

    printf("Enter the name: ");
    scanf("%s", word);

    
    strncpy(searchWord, word, 5);
    searchWord[5] = '\0';
    int len = strlen(searchWord);

    
    int hStartRow = 0, hStartCol = 0, hEndRow = 0, hEndCol = len-1;
    int vStartRow = 0, vStartCol = 0, vEndRow = len-1, vEndCol = 0;

    
    int foundH = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n - len; j++) {
            int k;
            for (k = 0; k < len; k++)
                if (grid[i][j + k] != searchWord[k])
                    break;
            if (k == len) {
                hStartRow = i; hStartCol = j;
                hEndRow = i; hEndCol = j + len - 1;
                foundH = 1;
                break;
            }
        }
        if(foundH) break;
    }

    
    int foundV = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= m - len; i++) {
            int k;
            for (k = 0; k < len; k++)
                if (grid[i + k][j] != searchWord[k])
                    break;
            if (k == len) {
                vStartRow = i; vStartCol = j;
                vEndRow = i + len - 1; vEndCol = j;
                foundV = 1;
                break;
            }
        }
        if(foundV) break;
    }


    printf("Horizontal: Start: (%d,%d) End: (%d,%d)\n", hStartRow, hStartCol, hEndRow, hEndCol);
    printf("Vertical: Start: (%d,%d) End: (%d,%d)\n", vStartRow, vStartCol, vEndRow, vEndCol);

    return 0;
}

