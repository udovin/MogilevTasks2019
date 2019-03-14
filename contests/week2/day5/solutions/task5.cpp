#include <bits/stdc++.h>

using namespace std;

struct Field {
	int n, m, l, h;
	vector<string> v;
};

istream &operator>>(istream &is, Field &f) {
	is >> f.n >> f.m >> f.l >> f.h;
	f.v.resize(f.n);
	for (int i = 0; i < f.n; ++i) {
		is >> f.v[i];
	}
	return is;
}

struct Rect {
	int x1, y1, x2, y2;
	
	inline int square() const {
		return (abs(x2-x1)+1) * (abs(y2-y1)+1);
	}
};

ostream &operator<<(ostream &os, const Rect &a) {
	return os << a.x1+1 << " " << a.y1+1 << " " << a.x2+1 << " " << a.y2+1;
}

struct Answer {
	vector<Rect> v;
	
	inline int totalSquare() const {
		int ans = 0;
		for (const Rect &r : v) {
			ans += r.square();
		}
		return ans;
	}
};

ostream &operator<<(ostream &os, const Answer &ans) {
	os << ans.v.size() << "\n";
	for (auto it : ans.v) {
		os << it << "\n";
	}
	return os;
}

template<typename T>
inline vector< vector<T> > matrix(int n, int m, T val = T()) {
	return vector< vector<T> >(n, vector<T>(m, val));
}

template<typename T = int>
struct PrefMat {
	int n, m;
	vector< vector<T> > p;
	
	inline T ask(int x1, int y1, int x2, int y2) {
		++x2; ++y2;
		return p[x2][y2] - p[x2][y1] - p[x1][y2] + p[x1][y1];
	}
	
	PrefMat(vector< vector<T> > v) : n(v.size()), m(v[0].size()), p(n+1, vector<T>(m+1)) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				p[i+1][j+1] = p[i][j+1] + p[i+1][j] - p[i][j] + v[i][j];
			}
		}
	}
};

inline Answer dpSolution(const Field &f) {
	const int MAXN = /*200*/100, MAXM = /*250*/100;
	static unsigned short dp[MAXN][MAXM][MAXN][MAXM] = {}; // RIP RAM
	
	int n = f.n, m = f.m;
	assert(n <= MAXN && m <= MAXM);
	
	cerr << "Initializing..." << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < m; ++l) {
					dp[i][j][k][l] = 0;
				}
			}
		}
	}
	cerr << "OK" << endl;
	
	auto cuprum = matrix<int>(n, m);
	auto ferrum = matrix<int>(n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			(f.v[i][j] == 'C' ? cuprum : ferrum)[i][j] = 1;
		}
	}
	
	auto pCuprum = PrefMat<int>(cuprum);
	auto pFerrum = PrefMat<int>(ferrum);
	
	int64_t needSteps = int64_t(1) * n * (n+1) / 2 * m * (m+1) / 2 * (n + m + 4) / 3;
	int64_t doneSteps = 0;
	
	const int progressShift = 30;
	int64_t lastCheckpoint = 0;
	
	clock_t time = clock();
	cerr << "Calculating DP..." << endl;
	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			for (int k = i; k < n; ++k) {
				for (int l = j; l < m; ++l) {
					do {
						/* basic check */
						if (
							pCuprum.ask(i, j, k, l) < f.l ||
							pFerrum.ask(i, j, k, l) < f.l
						) {
							break;
						}
						if ((k-i+1) * (l-j+1) <= f.h) {
							dp[i][j][k][l] = (k-i+1) * (l-j+1);
							break;
						}
						/* horizontal cut */
						for (int ch = i; ch < k; ++ch) {
							dp[i][j][k][l] = max<unsigned short>(dp[i][j][k][l], dp[i][j][ch][l] + dp[ch+1][j][k][l]);
						}
						/* vertical cut */
						for (int cv = j; cv < l; ++cv) {
							dp[i][j][k][l] = max<unsigned short>(dp[i][j][k][l], dp[i][j][k][cv] + dp[i][cv+1][k][l]);
						}
					} while (false);
					/* update progress */
					doneSteps += k-i+l-j+2;
					if ((doneSteps >> progressShift) != lastCheckpoint) {
						double tiempo = (clock() - time) * 1.0 / CLOCKS_PER_SEC;
						double progress = 100.0 * doneSteps / needSteps;
						cerr << "progress = " << fixed << setprecision(2) << progress << "%"
						        " steps = " << doneSteps <<
						        " total = " << needSteps <<
						        " time = " << fixed << setprecision(3) << tiempo << " s" <<
						        endl;
						lastCheckpoint = doneSteps >> progressShift;
					}
				}
			}
		}
	}
	double tiempo = (clock() - time) * 1.0 / CLOCKS_PER_SEC;
	cerr << "total steps = " << doneSteps << " expected steps = " << needSteps << endl;
	cerr << "dp time = " <<  fixed << setprecision(3) << tiempo << " seconds" << endl;
	cerr << "score = " << dp[0][0][n-1][m-1] << endl;
	
	cerr << "Restoring answer..." << endl;
	Answer ans;
	
	function<void(int, int, int, int)> restore = [&](int i, int j, int k, int l) {
		if (dp[i][j][k][l] == 0) {
			return;
		}
		if (
			pCuprum.ask(i, j, k, l) >= f.l && 
			pFerrum.ask(i, j, k, l) >= f.l &&
			(k-i+1) * (l-j+1) <= f.h
		) {
			ans.v.push_back({i, j, k, l});
			return;
		}
		for (int ch = i; ch < k; ++ch) {
			if (dp[i][j][k][l] == dp[i][j][ch][l] + dp[ch+1][j][k][l]) {
				restore(i, j, ch, l);
				restore(ch+1, j, k, l);
				return;
			}
		}
		for (int cv = j; cv < l; ++cv) {
			if (dp[i][j][k][l] == dp[i][j][k][cv] + dp[i][cv+1][k][l]) {
				restore(i, j, k, cv);
				restore(i, cv+1, k, l);
				return;
			}
		}
	};
	restore(0, 0, n-1, m-1);
	
	cerr << "Done. Enjoy the answer ;)" << endl;
	return ans;
}

inline Answer &operator+=(Answer &a, const Answer &b) {
	a.v.insert(end(a.v), begin(b.v), end(b.v));
	return a;
}

const string yellowText = "\033[33;1m";
const string normText = "\033[0m";

inline Answer askChunk(const Field &f, int i, int j, int k, int l) {
	cerr << yellowText << "Checking the chunk (" << i << ", " << j << ") :: (" << k << ", " << l << ")" << normText << endl;
	Field subfield;
	subfield.n = k-i+1;
	subfield.m = l-j+1;
	subfield.l = f.l;
	subfield.h = f.h;
	subfield.v.resize(subfield.n);
	for (int p = i; p <= k; ++p) {
		subfield.v[p-i] = f.v[p].substr(j, subfield.m);
	}
	auto ans = dpSolution(subfield);
	for (auto &it : ans.v) {
		it.x1 += i;
		it.y1 += j;
		it.x2 += i;
		it.y2 += j;
	}
	return ans;
}

inline Answer chunked(const Field &f, int ch, int cw) {
	int n = f.n, m = f.m;
	int nChunks = (n + ch - 1) / ch, mChunks = (m + cw - 1) / cw;
	int cntChunks = nChunks * mChunks;
	int doneChunks = 0;
	Answer ans;
	clock_t time = clock();
	for (int i = 0; i < n; i += ch) {
		for (int j = 0; j < m; j += cw) {
			int k = min(n, i+ch)-1;
			int l = min(m, j+cw)-1;
			ans += askChunk(f, i, j, k, l);
			++doneChunks;
			double progress = 100.0 * doneChunks / cntChunks;
			double tiempo = (clock() - time) * 1.0 / CLOCKS_PER_SEC;
			cerr << yellowText 
			     << "progress = " << fixed << setprecision(2) << progress << "%"
			     << " done = " << doneChunks << " "
			     << " total = " << cntChunks << " "
			     << " time  = " << fixed << setprecision(3) << tiempo << " s"
			     << normText << endl;
		}
	}
	cerr << yellowText << "total chunks = " << doneChunks << " expected chunks = " << cntChunks << normText << endl;
	cerr << yellowText << "score = " << ans.totalSquare() << normText << endl;
	return ans;
}

int main() {
	int musor; cin >> musor;
	Field f; cin >> f;
	//cout << dpSolution(f);
	//cout << chunked(f, f.n/5, f.m/4);
	cout << chunked(f, 50, 50);
	return 0;
}
