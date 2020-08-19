class Solution {
private:
    void mergeSort(vector<int> &nums, vector<int> &indice, vector<int> &aux, int l, int r, vector<int> &counter) {
        if (l + 1 >= r) return;
        int m = l + (r - l) / 2;
        mergeSort(nums, indice, aux, l, m, counter);
        mergeSort(nums, indice, aux, m, r, counter);
        merge(nums, indice, aux, l, m, r, counter);
    }
    void merge(vector<int> &nums, vector<int> &indice, vector<int> &aux, int l, int m, int r, vector<int> &counter) {
        int left = l, right = m;
        int rightCount = 0;
        for (int i=l;i<r;i++) {
            if (left >= m) aux[i] = indice[right++];
            else if (right >= r) {
                aux[i] = indice[left++];
                counter[aux[i]] += right - m;
            } else if (nums[indice[left]] <= nums[indice[right]]) {
                aux[i] = indice[left++];
                counter[aux[i]] += right - m;
            } else aux[i] = indice[right++];
        }
        for (int i=l;i<r;i++) {
            indice[i] = aux[i];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> indice(n), aux(n), counter(n, 0);
        for (int i=0;i<n;i++)
            indice[i] = i;
        mergeSort(nums, indice, aux, 0, n, counter);
        return counter;
    }
};
