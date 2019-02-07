#include <fstream>
#include <random>
#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

vector <int> a, b;
int n, m;

mt19937_64 rnd(time(NULL));

//const double MIN_T = 1e-5;
//const double MAX_T = 1000;

const int MAX_NUMBER_OF_MUTATIONS = 10;
const int MAX_NUMBER_OF_MUTATIONS = 10;

const int INF = 1000000000;

vector<vector<int>> best_ans;
vector<vector<vector<int>>> cur_ans;
int best_cost;

void mutation(vector<vector<int>>& a) {
	int cnt = rnd() % MAX_NUMBER_OF_MUTATIONS + 1;
	for (; cnt; --cnt) {
		int x = rnd() % n;
		int y = rnd() % m;
		a[x][y] = !a[x][y];
	}
}

int getCost(const vector<vector<int>>& cur) {
	int x = 0;
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		x = 0;
		for(int j = 0; j < m; ++j) {
			if ((cur[i][j] == 1) && ((j == 0) || (cur[i][j-1] == 0))) {
				x++;
			}
		}
		ans += (x - a[i]) * (x - a[i]);
	}
	for (int i = 0; i < m; ++i) {
		x = 0;
		for (int j = 0; j < n; ++j) {
			if ((cur[j][i] == 1) && ((j == 0) || (cur[j-1][i] == 0))) {
				x++;
			}
		}
		ans += (x - b[i]) * (x - b[i]);
	}
	return ans;
}

bool isTransition(double dE) {
	if (dE < 0) {
		return true;
	}
	
	return false;
}

void print(const string& file_name) {
	ofstream file_out(file_name);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			file_out << (best_ans[i][j] ? '*' : '.');
		}
		file_out << endl;
	}
	file_out.close();
}

void init(vector<vector<int> >& cur) {
	cur.assign(n, vector<int> (m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cur[i][j] = rnd() % 2;
		}
    }
    best_ans = cur;
    best_cost = getCost(cur);
}

int main() {
	ifstream file_in("input9.txt");
	file_in >> n >> m;
	//cin >> n >> m;
	a.resize(n);
	for(int& v : a)
		file_in >> v;
		//cin >> v;
	b.resize(m);
	for(int& v : b)
		file_in >> v;
		//cin >> v;
	file_in.close();

	init(cur_ans);
	int i = 1;
	while((best_cost != 0)) {
		mutation(cur_ans);
		int cur_cost = getCost(cur_ans);
		if(isTransition(cur_cost - best_cost)) {
			best_cost = min(best_cost, cur_cost);
			if (best_cost == cur_cost) {
				best_ans = cur_ans;
				print("temp.txt");
			}
		} else {
			cur_ans = best_ans;
		}
		/*T = MAX_T * 0.1 / i;*/ ++i;
		//T *= 0.99997;
		
		if (i % 100 == 0) {
			cout << i << " : " /*<< T << " - "*/ << best_cost <<endl;
		}
		
		
	}
	cout << best_cost << endl;
	
    print("output9.txt");
    /*
    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << (best_ans[i][j] ? '*' : '.');
		}
		cout << endl;
	}
	*/
	return 0;
}
