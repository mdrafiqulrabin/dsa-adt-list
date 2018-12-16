template<class T>
void purge(T &list) {
    int p, q;
    p = list.first();
    while (p != list.size()) {
        q = list.next(p);
        while (q != list.size()) {
            if (list.get(p) == list.get(q)) {
                list.remove(q);
            } else {
                q = list.next(q);
            }
        }
        p = list.next(p);
    }
}

template<class T>
int getMaxSum(T &list) {
    int n = list.size();
    int maxSum = 0;
    for (int lb = 0; lb < n; lb++) {
        for (int ub = lb; ub < n; ub++) {
            int sum = 0;
            for (int i = lb; i <= ub; i++) {
                sum += list.get(i);
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
