//ref: https://www.crocus.co.kr/1075
void manachers(string st, int n){
    int r = 0, p = 0;
    for (int i = 0; i < n; i++){
        arr[i] = (i <= r) ? min(arr[2 * p - i], r - i) : 0;
        while (i - arr[i] - 1 >= 0 && i + arr[i] + 1 < n && st[i - arr[i] - 1] == st[i + arr[i] + 1]) ++arr[i];
        if (r < i + arr[i])  r = i + arr[i], p = i;
    }
}
