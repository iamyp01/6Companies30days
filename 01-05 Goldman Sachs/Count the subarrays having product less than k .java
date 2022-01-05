class Solution {
    
    // Sliding Window
    public int countSubArrayProductLessThanK(long a[], long n, long k)
    {
        int cnt = 0;
        int l = 0, r = 0;
        long prod = 1;
        while(r < n){
            prod *= a[r];
            // when prod cross its limit move remove left most value by dividing and move left pointer
            // and all subsets till position can be counted using (r-l+1) because 
            // current value will make subset for each previous values
            while((prod >= k) && (l <= r)){
                prod /= a[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
}