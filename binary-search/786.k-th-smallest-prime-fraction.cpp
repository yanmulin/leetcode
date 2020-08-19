class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        double low = 0.0, high = 1.0;
        while (low < high) {
            double m = low + (high - low) / 2;
            int count = 0, i, j, p, q;
            double max_f = 0.0;
            for (i=j=0;i<n-1;i++) {
                while (j < n && A[i] > m * A[j]) j ++;
                if (j == n) break;
                count += n - j;
                double f = static_cast<double>(A[i]) 
                    / static_cast<double>(A[j]);
                if (max_f < f) {
                    max_f = f;
                    p = i;
                    q = j;
                }
            }
            if (count == K) return {A[p], A[q]};
            else if (count > K) high = m;
            else low = m;
        }
        return {};
    }
};
