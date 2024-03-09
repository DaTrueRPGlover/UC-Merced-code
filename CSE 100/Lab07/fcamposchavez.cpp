#include <bits/stdc++.h>
using namespace std;

int nrods;

int helper(int cost[], int rods[], int items){
    int value[items+1];
    int lastRod[items+1];
    value[0] = 0;
    int i, j;

    for (i = 1; i <= items; i++){
        int max_value = INT_MIN;
        int best_rod_len = -1;
        for (j = 0; j < i; j++){
            if(max_value < cost[j] + value[i-j-1]){
                max_value = cost[j] + value[i-j-1];
                best_rod_len = j;
            }
        }
        value[i] = max_value;
        lastRod[i] = best_rod_len + 1;
    }

    for (i = items, j = 0; i > 0; i -= lastRod[i]){
        rods[j++] = lastRod[i];
    }
    nrods = j;

    return value[items];
}


int main(){
    int items;
    cin >> items;
    int rodlen[items];

    for(int i = 0; i < items; i++){
        scanf("%d",&rodlen[i]);
    }

    int rods[items+1];
    int i;

    printf("%d\n", helper(rodlen, rods, items));

    printf("%d", rods[0]);

    for(i = 1; i < nrods; i++){
        printf(" %d", rods[i]);
    }

    cout << " -1";
    cout << "\n";

    return 0;
}