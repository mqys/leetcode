class Solution {
public:
    int countPrimes(int n) {
        // 316ms
        // vector<bool> isPrime(n, true);
        // for (int i = 2; i * i < n; ++i) {
        //     if (!isPrime[i]) continue; // only need to mark the number form by primes
        //     for (int j = i * i; j < n; j += i) { // i*i , i*i+i, i*i+2i ....
        //         isPrime[j] = false;
        //     }
        // }
        // int count = 0;
        // for (int i = 2; i < n; ++i) {
        //     if (isPrime[i])
        //         ++count;
        // }
        // return count;
        
        // 16ms
        if (n <= 2) return 0;
        int res=n>>1, m=sqrt(n-1); // intilize res to n/2, removes all even number(not 2) and 1
        bool *table=new bool[n];
        for(int i=3,j,step;i<=m;i+=2)
            if(!table[i]) { // i is an odd prime
                for(step=i<<1, j=i*i;j<n;j+=step) // step=i*2, ignore even numbers
                    if(!table[j]) { table[j]=1; --res; }
            }
        delete []table;
        return res;
    }
};