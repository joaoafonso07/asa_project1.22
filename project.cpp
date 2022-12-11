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

int max_tile(point p,int n){
    return min(p.x, n - p.y);
}






int main() {
    int n, m; //n = number of lines, m = number of columns 
    scanf("%i", &n);
    scanf("%i", &m);
    int c[n]; //array with n ci's
    int small;
    point exp_pt;
    
   for(int i = 0; i < n; i++){ // for each i less than n add the ci to the array
        scanf("%d", &c[i]);
    }

    for(int i = 0; i < n-1; i++){
        if (c[i] > 1){
            exp_pt.x = c[i];
            exp_pt.y = i + 1;
            break;
        }
    }

    int max = max_tile(exp_pt, n);


    return 0;
}