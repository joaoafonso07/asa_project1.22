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

int *remove_tile(int c[], int m, point p){ //m*m tile
    int i = p.y-1;
    for (i; i>=p.x - m; i--){
        c[i] -= m;
    }
    return c;
}

point next_exp_pt(int c[3], int n){
    point exp_pt;
    int m = max_func(c, n);
    for(int i = n; i >= 0; i--) {
        if(c[i] == m){
            exp_pt.x = m;
            exp_pt.y = i + 1;
            break;
        }
    }
    return exp_pt;
}


int tilling_numb(int c[], int n){
    return 0;
}


int main() {
    int n, m; //n = number of lines, m = number of columns 
    scanf("%i", &n);
    scanf("%i", &m);
    int c[n]; //array with n ci's
    
    
   for(int i = 0; i < n; i++){ // for each i less than n add the ci to the array
        scanf("%d", &c[i]);
    }

    point start = next_exp_pt(c, n);

    int mT = max_tile(c, start);
    int *i = remove_tile(c, mT, start);
    for (int j = 0; j < n; j++){
        printf("%d", i[j]);
    }
    return 0;
}
