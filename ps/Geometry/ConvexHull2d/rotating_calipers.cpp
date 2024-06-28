template<typename T>
T rotating_calipers(vector<pt<T>>& hull){
    T ans = numeric_limits<T>::min();
    int n = hull.size();
    int r = 0;
    for (int i = 0; i < n; i++){
        while (r < n * 2 && hull[i].cross(hull[(i + 1) % n], hull[(i + 1) % n] +
            hull[(r + 1) % n] - hull[r % n]) >= 0){
            ans = max(ans, (hull[i] - hull[r % n]).dist2());
            r++;
        }
        ans = max(ans, (hull[i] - hull[r % n]).dist2());
    }
    return ans;
}
