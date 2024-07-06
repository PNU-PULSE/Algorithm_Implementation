struct pt{
    T x, y;
    pt() : x(0), y(0) {}
    pt(T x, T y) : x(x), y(y) {}
    bool operator<(pt p) const{return ((x == p.x) ? (y < p.y) : (x < p.x));} //좌표 비교
    bool operator==(pt p) const{return ((x == p.x) && (y == p.y));}//위치 동일 판정
    pt operator+(pt b) {return {x + b.x, y + b.y};}// 위치의 합
    pt operator-(pt b) {return {x - b.x, y - b.y};}// 위치 차이
    pt operator*(T a) {return {x * a, y * a};}//스칼라 연산 곱셈
    pt operator/(T a) {return {x / a, y / a};}//스칼라 연산 나눗셈
    T dot(pt b) { return x * b.x + y * b.y;}//다른 점과 내적 연산
    T cross(pt b) const{ return x * b.y - y * b.x;}//(0, 0), 다른 점과 외적 연산
    T cross(pt a, pt b) const{return (a - *this).cross(b - *this);}// 세 점의 외적
    T dist2() const {return x * x + y * y;};//(0, 0)에서의 거리의 제곱
    ld dist() const {return sqrtl((ld)dist2());}//(0, 0)에서의 거리
    ld angle() const {return atan2l(y, x);}//(0, 0)과 (x, y)의 각도
    pt rotate(ld ag) const{return {x * cosl(ag) - y * sinl(ag), x * sinl(ag) + y * cosl(ag)};}//점의 회전
};
