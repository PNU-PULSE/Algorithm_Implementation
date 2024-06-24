//nearest 부분은 gpt 도움받아서 작성함
template <typename T>
struct Node {
    pt<T> point;
    Node* left;
    Node* right;
    Node(pt<T> pt) : point(pt), left(nullptr), right(nullptr) {}
};

template <typename T>
class KDTree {
public:
    ll n;
    vector<pt<T>> points;
    KDTree() {
        points.clear();
        cin >> n;
        points.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
            points[i].index = i; // 인덱스 설정
        }
        root = build_tree(points, 0);
    }

    void find_all_near(){
        for (int i = 0; i < n; i++){
            dist_best = numeric_limits<T>::max();
            auto pt = nearest(points[i], root, 0, {numeric_limits<T>::max(), numeric_limits<T>::max(), -1});
            cout << (points[i] - pt).dist2() << "\n";
        }
    }

private:
    Node<T>* root;
    mutable T dist_best;

    Node<T>* build_tree(vector<pt<T>> points, int depth) {
        if (points.empty()) return nullptr;
        int axis = depth % 2;
        sort(points.begin(), points.end(), [axis](pt<T> a, pt<T> b) {
            return (axis == 0) ? a.x < b.x : a.y < b.y;
        });
        int median = points.size() / 2;
        auto* node = new Node<T>(points[median]);
        vector<pt<T>> left_points(points.begin(), points.begin() + median);
        vector<pt<T>> right_points(points.begin() + median + 1, points.end());
        node->left = build_tree(left_points, depth + 1);
        node->right = build_tree(right_points, depth + 1);
        return node;
    }

    pt<T> nearest(const pt<T>& target, Node<T>* node, int depth, pt<T> best) const {
        if (node == nullptr) return best;

        T dist_node = (target - node->point).dist2();

        if (dist_node < dist_best && node->point.index != target.index) {
            best = node->point;
            dist_best = dist_node;
        }

        int axis = depth % 2;
        Node<T>* next_branch = (axis == 0 ? target.x < node->point.x : target.y < node->point.y) ? node->left : node->right;
        Node<T>* other_branch = (next_branch == node->left) ? node->right : node->left;

        best = nearest(target, next_branch, depth + 1, best);
        if ((axis == 0 ? abs(target.x - node->point.x) : abs(target.y - node->point.y)) < sqrtl(dist_best)) {
            best = nearest(target, other_branch, depth + 1, best);
        }

        return best;
    }
};
