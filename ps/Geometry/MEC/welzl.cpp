//ref: https://www.geeksforgeeks.org/minimum-enclosing-circle-using-welzls-algorithm/
using ld = long double;
struct circle{
    pt<ld> ct;
    ld R;
    circle(): ct({0, 0}), R(0) {}
    circle(pt<ld> p, ld R): ct(p), R(R) {}
};

pt<ld> calc_center(ld ax, ld ay, ld bx, ld by){
    ld b = ax * ax + ay * ay;
    ld c = bx * bx + by * by;
    ld d = ax * by - bx * ay;
    return {(by * b - ay * c) / (2 * d), (ax * c - bx * b) / (2 * d)};
}

//경계의 점이 2개로 이루어진 원
circle p2(pt<ld>& a, pt<ld>& b){
    auto c = (a + b) / 2.0;
    return {c, (a - b).dist() / 2.0};
}

//경계의 점이 3개로 이루어진 원
circle p3(pt<ld>& a, pt<ld>& b, pt<ld>& c){
    auto pp = calc_center(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
    pp.x += a.x; pp.y += a.y;
    return {pp, (pp - a).dist()};
}

//외접원이 맞는지 확인
bool enclosing(circle& c, vector<pt<ld>>& p){
    for (auto& pd: p){
        if ((c.ct - pd).dist() > c.R) return false;
    }
    return true;
}

//외접원 결정
circle min_circle(vector<pt<ld>>& p){
    if (p.empty()) return {{0, 0}, 0};
    else if (p.size() == 1) return {p[0], 0};
    else if (p.size() == 2) return p2(p[0], p[1]);
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            auto c = p2(p[i], p[j]);
            if (enclosing(c, p)) return c;
        }
    }
    return p3(p[0], p[1], p[2]);
}


circle welzl(vector<pt<ld>>& p, vector<pt<ld>> r, int n){
    if (!n || r.size() == 3) return min_circle(r);
    int idx = rand() % n;//점을 무작위로 선택함
    auto np = p[idx];
    swap(p[idx], p[n - 1]);
    auto nc = welzl(p, r, n - 1);//나머지 점들로 이루어진 외접원 계산
    if ((nc.ct - np).dist() <= nc.R) return nc;//만약 내부에 점이 존재하면 넘어감
    r.emplace_back(np);//아니면 경계에 점을 추가함.
    return welzl(p, r, n - 1);
}

circle func(const vector<pt<ld>>& p){
    vector<pt<ld>> parr(p);
    return welzl(parr, {}, p.size());
}
