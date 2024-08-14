//ref: antti laaksonen: Guide to Competitive Programming
using namespace std;
typedef long double ld;
using ll = long long;
using cd = complex<double>;
const double pi = acos(-1);
vector<cd> fft(vector<cd>& a, int d = 1){
    int n = a.size();
    vector<cd> r(n);
    for (int k = 0; k < n; k++){
        int b = 0;
        for (int z = 1; z < n; z <<= 1){
            b <<= 1;
            if (k & z) ++b;
        }
        r[b] = a[k];
    }

    for (int m = 2; m <= n; m <<= 1){
        cd wm = exp(cd{0, d*2*pi/m});
        for (int k = 0; k < n; k += m){
            cd w = 1;
            for (int j = 0; j < m / 2; j++){
                cd u = r[k + j];
                cd t = w * r[k + j + m / 2];
                r[k + j] = u + t;
                r[k + j + m / 2] = u - t;
                w = w * wm;
            }
        }
    }

    if (d == -1){
        for (int i = 0; i < n; i++) r[i] /= n;
    }
    return r;
}
