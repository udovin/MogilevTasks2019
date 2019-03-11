/*------------------------------------------------+
|                     alex256                     |
+---------+---------------------------------------+
| Contest | Educational CodeForces Round #19      |
| Task    | E                                     |
| Date    | 15.04.2017                            |
+---------+--------------------------------------*/
/// Global defines
#ifndef ONLINE_JUDGE
	#define LOCAL
#endif
//#define USE_LONGLONG
//#define USE_UNORDERED
//#define FILE_IO
//#undef LOCAL
#ifdef FILE_IO
	#define TASK_NAME "taskname"
	#define INPUT_FILE TASK_NAME".in"
	#define OUTPUT_FILE TASK_NAME".out"
#endif
/// Includes 
#include <bits/stdc++.h>
using namespace std;
/// Defines
#ifdef USE_UNORDERED
	#define set unordered_set
	#define map unordered_map
#endif
#if defined(FILE_IO) && (!defined(LOCAL))
	#define cin __new_cin
	#define cout __new_cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#endif
#ifdef USE_LONGLONG
	#define int ll
	#define inf llInf
#endif
#define endl "\n"
#define sz(a) (int)(a.size())
#define here dbg("here!")
#define endless for (;;)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define mp make_pair
/// Types
typedef int64_t ll;
typedef uint64_t ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
struct ofl { ld value; int precision; inline ofl(ld value, int precision) : value(value), precision(precision) {} };
/// Constants
const int seed = hash<string>()("alex256");
#ifndef USE_LONGLONG
	const int inf = (int)1e9 + 7;
#endif
const ll llInf = (ll)2e18 + 256;
const int mod = (int)1e9 + 7;
const ld pi = 3.141592653589793238462643383279502884197169399375105821;
const string luck = "🍀";
const char* errText = "error :(";
/// Iostream extension
template<typename T1, typename T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) { return is >> p.F >> p.S; } 
template<typename T1, typename T2> inline ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << p.F << " " << p.S; } 
template<typename T> inline istream& operator>>(istream& is, vector<T>& v) { for (int i = 0; i < sz(v); i++) { is >> v[i]; } return is; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (int i = 0; i < sz(v); i++) { if (i) { os << " "; } os << v[i]; } return os; }
inline ostream& operator<<(ostream& os, const ofl& o) { return os << fixed << setprecision(o.precision) << o.value; }
inline bool iosOptimize() { ios_base::sync_with_stdio(false); return true; }
bool iosOptimized = iosOptimize();
/// Input
template<typename T> inline T get() { T value; cin >> value; return value; }
template<> inline char get() { char c = '\0'; while (c <= ' ') { cin >> c; } return c; }
inline string getLn() { string s; getline(cin, s); return s; }
template<typename T, size_t Count> struct VectorPacker { typedef vector< typename VectorPacker<T, Count-1>::Type > Type; };
template<typename T> struct VectorPacker<T, 0> { typedef T Type; };
template<typename T> inline vector<T> getVector(int size) { vector<T> res(size); cin >> res; return res; }
template<typename T, typename U, typename... Args> inline typename VectorPacker<T, sizeof...(Args)+1>::Type getVector(U size, Args... sizes) { typename VectorPacker<T, sizeof...(Args)+1>::Type res(size); for (int i = 0; i < (int)size; i++) { res[i] = getVector<T>(sizes...); } return res; }
/// Output
inline void put() {}
template<typename T, typename... Args> inline void put(const T& value, const Args&... vals) { cout << value; put(vals...); }
template<typename... Args> inline void putLn(const Args&... vals) { put(vals...); cout << endl; }
/// Debug
#ifdef LOCAL
	template<typename... Args> inline void dbg(const Args&... vals) { putLn(vals...); cout.flush(); }
#else
	#define dbg(...)
#endif
/// Hash overload for pairs
namespace std { template<typename T1, typename T2> struct hash<pair<T1, T2> > { inline size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.F) ^ hash<T2>()(p.S); } }; };
/// Helpful methods
mt19937_64 rnd(seed);
inline void error(const char* text = errText) { dbg(text); exit(256); }
template <typename T1, typename T2> inline void umax(T1& a, const T2& b) { if (a < b) { a = b; } }
template <typename T1, typename T2> inline void umin(T1& a, const T2& b) { if (a > b) { a = b; } }
ll gcd(ll a, ll b) { return b ? gcd (b, a % b) : a; }
ll extGcd(ll a, ll b, ll& x, ll& y) { if (!a) { x = 0; y = 1; return b; } ll x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
inline int addMod(int a, int b, int m = mod) { return ((ll)a + b) % m; }
inline int subMod(int a, int b, int m = mod) { return ((ll)a + m - b) % m; }
inline int mulMod(int a, int b, int m = mod) { return ((ll)a * b) % m; }
inline int divMod(int a, int b, int m = mod) { ll x, y; ll g = extGcd(b, m, x, y); if (g != 1) { dbg("cannot eval ", a, " / ", b, " modulo ", m); exit(42); }  x = (x % m + m) % m; return mulMod(a, x, m); }
/// End of The Template

class BinaryLift {
	private:
		int n;
		int l;
		int **go;
		
		inline int** cloneArray() const {
			int **res = new int*[l+1];
			for (int i = 0; i <= l; i++) {
				res[i] = new int[n+1];
				for (int j = 0; j <= n; j++) {
					res[i][j] = go[i][j];
				}
			}
			return res;
		}
		
		inline void freeArray() {
			if (go != nullptr) {
				for (int i = 0; i <= l; i++) {
					delete[] go[i];
				}
				delete[] go;
			}
		}
	public:
		inline int wayToGoOut(int v) {
			if (v == 0) {
				return 0;
			}
			int res = 0;
			for (int i = l; i >= 0; i--) {
				if (go[i][v] != 0) {
					v = go[i][v];
					res += 1 << i;
				}
			}
			return res + 1;
		}
		
		BinaryLift(vector<int> v, int l) 
			: n(sz(v)), l(l) {
			go = new int*[l+1];
			for (int i = 0; i <= l; i++) {
				go[i] = new int[n+1];
			}
			go[0][0] = 0;
			for (int i = 1; i <= n; i++) {
				go[0][i] = v[i-1] + 1;
			}
			for (int i = 1; i <= l; i++) {
				for (int j = 0; j <= n; j++) {
					go[i][j] = go[i-1][go[i-1][j]];
				}
			}
		}
		
		inline BinaryLift& operator=(const BinaryLift& lift) {
			n = lift.n;
			l = lift.l;
			freeArray();
			go = lift.cloneArray();
			return *this;
		}
		
		BinaryLift() {
			go = nullptr;
		}
		
		~BinaryLift() {
			freeArray();
		}
};

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n = get<int>();
	vi a = getVector<int>(n);
	
	const int LIFT_RANGE = 32;
	BinaryLift lifts[LIFT_RANGE] = {};
	
	for (int k = 1; k < LIFT_RANGE; k++) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			int nxt = i + a[i] + k;
			if (nxt >= n) {
				nxt = -1;
			}
			v[i] = nxt;
		}
		lifts[k] = BinaryLift(v, 17);
	}
	
	int q = get<int>();
	while (q--) {
		int p = get<int>() - 1, k = get<int>();
		if (k < LIFT_RANGE) {
			putLn(lifts[k].wayToGoOut(p+1));
		} else {
			int ans = 0;
			while (p < n) {
				p = p + a[p] + k;
				ans++;
			}
			putLn(ans);
		}
	}
	return 0;
}
