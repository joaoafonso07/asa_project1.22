#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct{
    int x; //horizontal
    int y; //vertical
}point;

int max_tile(point p,int n);
point next_exp_pt(int c[], int n);

int max_tile(point p,int n){
    return min(p.x, n - p.y);
}

point next_exp_pt(int c[], int n, point previous){
    point exp_pt;
    
    for(int i = 0; i < n-1; i++){
        if (c[i] > 1){
            exp_pt.x = c[i];
            exp_pt.y = i + 1;
            return exp_pt;
        }
    }
    exp_pt.x = -1;
    return exp_pt;
}

int tilling_numb(int c[], int n){
    point exp_pt = next_exp_pt(c, n);
    int max = max_tile(exp_pt, n);
    for (max; max > 0; max--){
        tilling_numb()
    }
}

int main() {
    int n, m; //n = number of lines, m = number of columns 
    scanf("%i", &n);
    scanf("%i", &m);
    int c[n]; //array with n ci's
    
    
   for(int i = 0; i < n; i++){ // for each i less than n add the ci to the array
        scanf("%d", &c[i]);
    }


    tilling_numb(c, n);

    return 0;
}