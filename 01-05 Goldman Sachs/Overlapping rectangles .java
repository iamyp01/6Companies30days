class Solution {
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // Left and RIght Side
        if(L1[0] > R2[0] || R1[0] < L2[0]) return 0;
        // UP and Down Side
        if(L1[1] < R2[1] || R1[1] > L2[1]) return 0;
        // otherwise overlap
        return 1;
    }
};