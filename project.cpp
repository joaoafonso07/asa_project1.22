#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
//#include <array>
 
#include <bits/stdc++.h> //if max_element doesn't work it's because of this
using namespace std;

typedef struct{
    int x; //horizontal
    int y; //vertical
}point;

int result = 0;

int max_tile (int c[], point p);
point next_exp_pt(int c[], int n);

int max_func(int c[], int n){
    int max = 0;
    for(int i = 0; i < n ; i++){
        if (c[i] > max)
            max=c[i];
    }
    return max;
}


int max_tile(int c[], point p){
    int tiles_above = 0, i = p.y-1;
    while(i >= 0){
        if (c[i] < p.x)
            break;
        tiles_above++;
        i--;
    }
    return min(p.x, tiles_above);
}

int *remove_tile(int c[], int m, point p, int n){ //m*m tile
    int i = p.y-1;
    while(i>=p.y - m){
        c[i] -= m;
        i--;
    }
    return c;
}

point next_exp_pt(int c[], int n){
    point exp_pt;
    int m = max_func(c, n);
    for(int i = n - 1; i >= 0; i--) {
        if(c[i] == m){
            exp_pt.x = m;
            exp_pt.y = i + 1;
            break;
        }
    }
    return exp_pt;
}


void tilling_numb(int c[], int n){
    point p = next_exp_pt(c, n);
    if(p.x == 0){
        result++;
        return;
    }
    int m = max_tile(c, p);
    while (m > 0){
        int* c1 =  (int*)malloc(n * sizeof(int));
        memcpy(c1, c, n*sizeof(int));
        if (c1 == NULL)
                return;

        int *c2 = remove_tile(c1, m, p, n);
        tilling_numb(c2, n);
        free(c1);
        m--;
    }
    
    return;
}


int main() {
    int n, m; //n = number of lines, m = number of columns 
    if(scanf("%i", &n) == -1)
        return -1;
    if(scanf("%i", &m) == -1)
        return -1;
    int c[n]; //array with n ci's
    
    
   for(int i = 0; i < n; i++){ // for each i less than n add the ci to the array
        if(scanf("%d", &c[i]) == -1)
            return -1;
    }
    /*
    point start = next_exp_pt(c, n);

    int mT = max_tile(c, start);
    int *i = remove_tile(c, mT, start);
    for (int j = 0; j < n; j++){
        printf("%d", i[j]);
    }
    */
    tilling_numb(c, n);
    printf("%d", result);
    return 0;
}
