#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; //n = number of lines, m = number of columns 
    scanf("%d\n%d\n", n, m);
    
    int c[m]; //array with m ci's

    for(int i = 0; i < m; i++){ // for each i less than m add the ci to the array
        scanf("%d\n", c[i]);
    }
    
    return 0;
}