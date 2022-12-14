#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct{
    short x; //horizontal
    short y; //vertical
}point;

long result = 0;

short max_tile (short c[], point p);
point next_exp_pt(short c[], short n);

short max_func(short c[], short n){
    short max = 0;
    for(short i = 0; i < n ; i++){
        if (c[i] > max)
            max=c[i];
    }
    return max;
}


short max_tile(short c[], point p){
    short tiles_above = 0, i = p.y-1;
    while(i >= 0){
        if (c[i] < p.x)
            break;
        tiles_above++;
        i--;
    }
    return min(p.x, tiles_above);
}

short *remove_tile(short c[], short m, point p, short n){ //m*m tile
    short i = p.y-1;
    while(i>=p.y - m){
        c[i] -= m;
        i--;
    }
    return c;
}

point next_exp_pt(short c[], short n){
    point exp_pt;
    short m = max_func(c, n);
    if (m <= 1){ 
        exp_pt.x = 0;
        return exp_pt; 
    }
    for(short i = n - 1; i >= 0; i--) {
        if(i == 0){
            c[i] = c[1];
            return next_exp_pt(c, n);
        }
        if(c[i] == m){
            exp_pt.x = m;
            exp_pt.y = i + 1;
            break;
        }
    }
    return exp_pt;
}


long tilling_numb(short c[], short n){
    point p = next_exp_pt(c, n);
    int result_tn = 0;
    if(p.x == 0){
        result_tn++;
        return result_tn;
    }
    short m = max_tile(c, p);
    while (m > 0){
        short* c1 =  (short*)malloc(n * sizeof(short));
        memcpy(c1, c, n*sizeof(short));
        if (c1 == NULL)
                return -1;

        short *c2 = remove_tile(c1, m, p, n);
        result_tn += tilling_numb(c2, n);
        free(c1);
        m--;
    }
    
    return result_tn;
}


int main() {
    short n, m; //n = number of lines, m = number of columns 
    bool empty = true;
    if(scanf("%hu", &n) == -1)
        return -1;
    if(scanf("%hu", &m) == -1)
        return -1;
    short c[n]; //array with n ci's
    
    
   for(short i = 0; i < n; i++){ // for each i less than n add the ci to the array
        if(scanf("%hu", &c[i]) == -1)
            return -1;
        if(empty == true && c[i] != 0)
            empty = false;
    }
    if(!empty){
        result = tilling_numb(c, n);
    }else
        result = 0;

    cout << result << "\n";
    return 0;
}
