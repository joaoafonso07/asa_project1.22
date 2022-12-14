#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

typedef struct{
    short x; //horizontal
    short y; //vertical
}point;

short max_tile (vector <short> c, point p);
point next_exp_pt(vector <short> c, short n);

short max_func(vector <short> c, short n){
    short max = 0;
    for(short i = 0; i < n ; i++){
        if (c[i] > max)
            max=c[i];
    }
    return max;
}

struct vector_hasher {
    int operator()(const vector<short> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

unordered_map<vector<short>, long, vector_hasher> map;

short max_tile(vector <short> c, point p){
    short tiles_above = 0, i = p.y-1;
    while(i >= 0){
        if (c[i] < p.x)
            break;
        tiles_above++;
        i--;
    }
    return min(p.x, tiles_above);
}

vector<short> remove_tile(vector<short> c, short m, point p, short n){ //m*m tile
    short i = p.y-1;
    while(i>=p.y - m){
        c[i] -= m;
        i--;
    }
    return c;
}

point next_exp_pt(vector <short> c, short n){
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


long tilling_numb(vector <short> c, short n){
    if(map.find(c) != map.end())
        return map[c];
    
    point p = next_exp_pt(c, n);
    int result_tn = 0;
    if(p.x == 0){
        result_tn++;
        return result_tn;
    }
    short m = max_tile(c, p);
    while (m > 0){
        vector <short> c1 = c;
       
        vector <short> c2 = remove_tile(c1, m, p, n);
        result_tn += tilling_numb(c2, n);
        m--;
    }
    map[c] = result_tn;
    return result_tn;
}


int main() {
    short n, m, add; //n = number of lines, m = number of columns 
    long result;
    bool empty = true;
    if(scanf("%hu", &n) == -1)
        return -1;
    if(scanf("%hu", &m) == -1)
        return -1;

    std::vector<short> c; //array with n ci's
    for(short i = 0; i < n; i++){ // for each i less than n add the ci to the array
        if(scanf("%hu", &add) != 1)
            return -1;
        c.push_back(add);
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
