#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string translate(int i) {
	string ans = "00";
	ans[0] = char('0' + i / 10);
	ans[1] = char('0' + i % 10);
	ans = "../tests/tests/" + ans;
	return ans;
}

mt19937_64 rnd(42);

vector < pair < pair <int, int>, int> > g;

void generateTree(int n) {
	g.clear();
	if (n == 1) return;
	vector <int> toadd(n);
	vector <int> added;
	for (int i = 0; i < n; i++) {
		toadd[i] = i;
	}
	shuffle(toadd.begin(), toadd.end(), rnd);
	int z1 = rnd() % toadd.size();
	swap(toadd[z1], toadd[toadd.size() - 1]);
	added.push_back(toadd.back());
	z1 = toadd.back();
	toadd.pop_back();

	int z2 = rnd() % toadd.size();
	swap(toadd[z2], toadd[toadd.size() - 1]);
	added.push_back(toadd.back());
	z2 = toadd.back();
	toadd.pop_back();
	g.push_back({{z1 + 1, z2 + 1}, rnd() % 2 + 1});
	for (int i = 0; i < n - 2; i++) {
		z2 = rnd() % added.size();
		z2 = added[z2];
		z1 = rnd() % toadd.size();
		swap(toadd[z1], toadd[toadd.size() - 1]);
		added.push_back(toadd.back());
		z1 = toadd.back();
		toadd.pop_back();
		g.push_back({{z1 + 1, z2 + 1}, rnd() % 2 + 1});		
	}
}

void work(int n, int z) {
	generateTree(n);
	ofstream out_in(translate(z));
	out_in << n << "\n";
	for (int i = 0; i < n - 1; i++) {
		out_in << g[i].first.first << " " << g[i].first.second << " " << g[i].second << "\n";
	}
	out_in.close();
}

int main() {
	for (int i = 1; i <= 15; i++) {
		int n = rnd() % 20 + 1;
		work(n, i);
		//cout << (translate(i) + ".a") << endl;
	}
	for (int i = 16; i <= 30; i++) {
		int n = rnd() % 1000 + 4000 + 1;
		work(n, i);
		//cout << (translate(i) + ".a") << endl;
	}
	for (int i = 30; i <= 50; i++) {
		int n = rnd() % 20000 + 80000 + 1;
		work(n, i);
		//cout << (translate(i) + ".a") << endl;
	}
	return 0;
}
