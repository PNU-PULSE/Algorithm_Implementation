//overflow를 대비해서 cross 부분은 양수 또는 음수에 따라 1, 0, -1로 전처리해주는게 좋습니다.
template <typename T>
bool line_cross(const pt<T>& a, const pt<T>& b, const pt<T>& c, const pt<T>& d) {
    T abc = a.cross(b, c), abd = a.cross(b, d);
    T cda = c.cross(d, a), cdb = c.cross(d, b);
    
    if (abc * abd <= 0 && cda * cdb <= 0) {
        if (abc * abd == 0 && cda * cdb == 0) {
            if (std::max(a.x, b.x) >= std::min(c.x, d.x) && std::max(c.x, d.x) >= std::min(a.x, b.x) &&
                std::max(a.y, b.y) >= std::min(c.y, d.y) && std::max(c.y, d.y) >= std::min(a.y, b.y)) return true;
            return false;
        }
        return true;
    }
    return false;
}
