

result = 0;

def max_func(c, n){
    max = 0;
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
    for (i; i>=p.y - m; i--){
        c[i] -= m;
    }
    return c;
}

point next_exp_pt(int c[], int n){
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


void tilling_numb(int c[], int n){
    int* c1 =  (int*)malloc(n * sizeof(int));
    memcpy(c1, c, n*sizeof(int));
    if (c1 == NULL)
        return;
    point p = next_exp_pt(c, n);
    if(p.x == 0){
        result++;
        return;
    }
    int m = max_tile(c, p);
    for (m; m > 0; m--){
        int *c2 = remove_tile(c1, m, p, n);

        for (int j = 0; j < n; j++){
        printf("%d", c2[j]);
    }
        tilling_numb(c2, n);
    }
    free(c1);
    return;
}


def main():
    n = input()
    m = input()
    
    c = []
    
   for i in range(0, n):
    inp = int(input())
    c.append(inp)

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
