template <typename T>
vector<pt<T>> hull(vector<pt<T>>& vec, int n) {
    swap(*min_element(vec.begin(), vec.end()), vec[0]);
    pt<T> point = vec[0];
    sort(vec.begin() + 1, vec.end(), [point](pt<T> a, pt<T> b){
        T ccw = point.cross(a, b);
        if (ccw != 0)   return ccw > 0;
        return (a - point).dist2() < (b - point).dist2();
    });
    vector<pt<T>> st;
    for (auto now: vec){
        while (st.size() > 1 && st[st.size() - 2].cross(st[st.size() - 1], now) <= 0){
            st.pop_back();
        }
        st.emplace_back(now);
    }

    return st;
}
