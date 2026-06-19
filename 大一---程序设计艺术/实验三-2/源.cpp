#include <iostream> 
#include <utility> 
#include <vector> 
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;
typedef pair<double, double> POINT;
// function dirction determines the direction that the segment 
//p1p turns to p2p with respect to point p 
//if return value is positive, means clockwise; 
//if return value is negative, menas counter-clockwise; 
// naught means on the same line; 
double direction(POINT p, POINT p1, POINT p2)
{
    POINT v1, v2;
    v1.first = p2.first - p.first;
    v1.second = p2.second - p.second;
    v2.first = p1.first - p.first;
    v2.second = p1.second - p.second;
    return v1.first * v2.second - v1.second * v2.first;
}
//function on_segment determines whether the point p is on the segment p1p2
bool on_segment(POINT p, POINT p1, POINT p2)
{
    double min_x = p1.first < p2.first ? p1.first : p2.first;
    double max_x = p1.first > p2.first ? p1.first : p2.first;
    double min_y = p1.second < p2.second ? p1.second : p2.second;
    double max_y = p1.second > p2.second ? p1.second : p2.second;
    if (p.first >= min_x && p.first <= max_x
        && p.second >= min_y && p.second <= max_y) return true;
    else return false;
}
//point startPoint is the polor point that is needed for comparing two other points;
POINT startPoint;
//function sortByPolorAngle provides the realizing of comparing two points, which support
//the STL function sort(); 
bool sortByPolorAngle(const POINT& p1, const POINT& p2)
{
    double d = direction(startPoint, p1, p2);
    if
        (d < 0) return true;
    if
        (d > 0) return false;
    if (d == 0 && on_segment(startPoint, p1, p2))return true;
    if (d == 0 && on_segment(p2, startPoint, p1)) return true;
    return false;
}
//here realizes the process of finding convex hull - 59 - 60
void find_convex_hull(vector<POINT> &point)
{
    POINT p0 = point[0];
    int k = 0;
    for (int i = 1; i < point.size(); i++)
    {
        if (point[i].second < p0.second ||
            point[i].second == p0.second && point[i].first < p0.first)
        {
            p0 = point[i];
            k = i;
        }
    }
    point.erase(point.begin() + k);
    point.insert(point.begin(), p0);
    vector<POINT> convex_hull;
    do {
        convex_hull.push_back(point[0]);
        startPoint = point[0];
        point.erase(point.begin());
        sort(point.begin(), point.end(), sortByPolorAngle);
        if (point[0] == convex_hull[0]) break;
        point.push_back(convex_hull[convex_hull.size() - 1]);
    } while (1);
    for (int i = 0; i < convex_hull.size(); i++)
    {
        cout << convex_hull[i].first << ' '
            << convex_hull[i].second << endl;
    }
}

// ---------- test driver ----------
// Helper: capture find_convex_hull output and return parsed hull vertices
vector<POINT> run_hull(vector<POINT> pts) {
    stringstream ss;
    streambuf* old_buf = cout.rdbuf(ss.rdbuf());  // redirect cout
    find_convex_hull(pts);
    cout.rdbuf(old_buf);                           // restore
    vector<POINT> result;
    double x, y;
    while (ss >> x >> y)
        result.push_back({x, y});
    return result;
}

// Helper: compare two point vectors within floating-point tolerance
bool hulls_equal(const vector<POINT>& a, const vector<POINT>& b, double eps = 1e-9) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i)
        if (fabs(a[i].first - b[i].first) > eps || fabs(a[i].second - b[i].second) > eps)
            return false;
    return true;
}

int main() {
    int passed = 0, failed = 0;

    // --- Test 1: convex quadrilateral (square) ---
    {
        vector<POINT> pts = {{0,0}, {4,0}, {4,3}, {0,3}};
        vector<POINT> got = run_hull(pts);
        // Expected: (0,0) -> (4,0) -> (4,3) -> (0,3) in CCW order from lowest-leftmost
        vector<POINT> expected = {{0,0}, {4,0}, {4,3}, {0,3}};
        if (hulls_equal(got, expected)) {
            cout << "[PASS] Test 1: convex quadrilateral" << endl;
            ++passed;
        } else {
            cout << "[FAIL] Test 1: convex quadrilateral — expected (0,0)(4,0)(4,3)(0,3)" << endl;
            cout << "       got: ";
            for (auto& p : got) cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
            ++failed;
        }
    }

    // --- Test 2: convex triangle ---
    {
        vector<POINT> pts = {{0,0}, {5,0}, {2,4}};
        vector<POINT> got = run_hull(pts);
        // Expected: (0,0) -> (5,0) -> (2,4)
        vector<POINT> expected = {{0,0}, {5,0}, {2,4}};
        if (hulls_equal(got, expected)) {
            cout << "[PASS] Test 2: convex triangle" << endl;
            ++passed;
        } else {
            cout << "[FAIL] Test 2: convex triangle — expected (0,0)(5,0)(2,4)" << endl;
            cout << "       got: ";
            for (auto& p : got) cout << "(" << p.first << "," << p.second << ") ";
            cout << endl;
            ++failed;
        }
    }

    // --- Summary ---
    cout << "\n" << passed << " passed, " << failed << " failed out of " << (passed + failed) << " tests." << endl;
    return failed ? 1 : 0;
}