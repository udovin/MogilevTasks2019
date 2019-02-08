#include <bits/stdc++.h>
using namespace std;

int64_t getCost(const vector<int>& p, int n, const vector<int>& a, const vector<vector<int>>& w) {
	int64_t cost(0);
	for (int i = 1; i < n; i++) {
		cost += (w[p[i - 1]][p[i]] + (i & a[p[i - 1]])) ^ a[p[i]];
	}
	return cost;
}

vector<int> getRandomPermutation(int n) {
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		p[i] = i;
	random_shuffle(p.begin(), p.end());
	return p;
}

vector<int> mutate(vector<int> p) {
	for (int i = 0; i < 5; i++) {
		int x = rand() % p.size();
		int y = rand() % p.size();
		swap(p[x], p[y]);
	}
	return p;
}

void solveTest(const std::string& input, const std::string& output) {
	cout << input << " -> " << output << endl;
	int n;
	ifstream fin(input.c_str());
	fin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		fin >> a[i];
	}
	vector<vector<int>> w(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fin >> w[i][j];
		}
	}
	set<pair<int64_t, vector<int>>> generation;
	while (generation.size() < 10) {
		vector<int> p(getRandomPermutation(n));
		generation.insert(make_pair(getCost(p, n, a, w), p));
	}
	for (int iter = 0; iter <= 1000000; iter++) {
		vector<vector<int>> mutations;
		for (auto item : generation) {
			for (int i = 0; i < 10; i++) {
				mutations.push_back(mutate(item.second));
			}
		}
		for (auto item : mutations) {
			generation.insert(make_pair(getCost(item, n, a, w), item));
		}
		while (generation.size() > 10) {
			generation.erase(prev(generation.end()));
		}
		if (iter % 100000 == 0) {
			cout << generation.begin()->first << endl;
		}
	}
	ofstream fout(output.c_str());
	for (int p : generation.begin()->second)
		fout << p + 1 << ' ';
}

int main() {
	for (int i = 0; i < 10; i++) {
		stringstream input, output;
		input << "inputs/input" << i + 1 << ".txt";
		output << "outputs/output" << i + 1 << ".txt";
		solveTest(input.str(), output.str());
	}
	return 0;
}