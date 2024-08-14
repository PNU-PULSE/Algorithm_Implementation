//tip: python에서는 pow(n, k, p): n^k mod p를 최적화해서 계산해주므로 참고하자. python에서 pow(n, k) % p는 pow(n, k, p)와 다르게 느리므로 주의
using ll = long long;
ll ebs(ll v, ll p, ll mod){
    if (p == 1)  return v;
    ll rt = ebs(v, p / 2, mod); rt = (rt * rt) % mod;
    if (p % 2)  rt = (rt * v) % mod;
    return rt;
}
