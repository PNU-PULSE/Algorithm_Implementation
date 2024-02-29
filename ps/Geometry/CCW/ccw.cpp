ll ccw(pt a, pt b, pt c){//pt의 cross(b, c)와 동일한 함수입니다.
    return (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y);
}
