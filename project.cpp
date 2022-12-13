#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
//#include <array>
 
//#include <bits/stdc++.h> if max_element doesn't work it's because of this
using namespace std;

typedef struct{
    int x; //horizontal
    int y; //vertical
}point;

int max_tile (int c[], point p);
point next_exp_pt(int c[], int n);

int max_func(int c[]){
    // Compute the sizes
    int n = sizeof(c) / sizeof(c[0]);
 
    // Find the maximum element
    return *max_element(c, c + n);
}


int max_tile(int c[], point p){
    int tiles_above = 0, i = p.y-1;
    while(true){
        if (c[i] < p.x)
            break;
        tiles_above++;
        i--;
    }
    return min(p.x, tiles_above);
}

point next_exp_pt(int c[], int n){
    point exp_pt;
    int m = max_func(c);
    for(int i = n; i <= 0; i--) {
        if(c[i] == m){
            exp_pt.x = m;
            exp_pt.y = i + 1;
        }
    }
    return exp_pt;
}

/*
int tilling_numb(int c[], int n){
    point exp_pt = next_exp_pt(c, n);
    int max = max_tile(exp_pt, n);
    for (max; max > 0; max--){
        tilling_numb()
    }
}
*/

int main() {
    int n, m; //n = number of lines, m = number of columns 
    scanf("%i", &n);
    scanf("%i", &m);
    int c[n]; //array with n ci's
    
    
   for(int i = 0; i < n; i++){ // for each i less than n add the ci to the array
        scanf("%d", &c[i]);
    }
    point start = next_exp_pt(c, n);

    int mT = max_tile(c, start, n);

    return 0;
}
