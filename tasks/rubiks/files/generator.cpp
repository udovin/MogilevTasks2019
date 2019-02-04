#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

class RubiksCube {
private:
	vector<vector<vector<char>>> faces;

	void swap(char& a, char& b, char& c, char& d, bool reverse) {
		char e = d;
		if (reverse) {
			d = a; a = b;
			b = c; c = e;
		} else {
			d = c; c = b;
			b = a; a = e;
		}
	}

	void rotateFace(vector<vector<char>>& a, bool reverse) {
		swap(a[0][0], a[0][2], a[2][2], a[2][0], reverse);
		swap(a[0][1], a[1][2], a[2][1], a[1][0], reverse);
	}

public:
	RubiksCube()
		: faces(6, vector<vector<char>>(3, vector<char>(3))) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				faces[0][i][j] = 'Y';
				faces[1][i][j] = 'B';
				faces[2][i][j] = 'W';
				faces[3][i][j] = 'R';
				faces[4][i][j] = 'G';
				faces[5][i][j] = 'O';
			}
		}
	}

	friend istream& operator>>(istream& is, RubiksCube& cube);

	operator string() const {
		stringstream ss;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				ss << faces[0][i][j];
			ss << '\n';
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				ss << faces[1][i][j];
			for (int j = 0; j < 3; j++)
				ss << faces[3][i][j];
			for (int j = 0; j < 3; j++)
				ss << faces[4][i][j];
			for (int j = 0; j < 3; j++)
				ss << faces[5][i][j];
			ss << '\n';
		}
		for (int i = 0; i < 3; i++) {
			if (i > 0)
				ss << '\n';
			for (int j = 0; j < 3; j++)
				ss << faces[2][i][j];
		}
		return ss.str();
	}

	int getScore() const {
		int score = 0;
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					if (faces[i][j][k] == faces[i][1][1])
						score++;
		return score - 6;//static_cast<double>(k - 6) / 48;
	}

	void rotateLeft(bool reverse) {
		rotateFace(faces[5], reverse);
		swap(faces[0][0][0], faces[1][0][0], faces[2][0][0], faces[4][2][2], reverse);
		swap(faces[0][1][0], faces[1][1][0], faces[2][1][0], faces[4][1][2], reverse);
		swap(faces[0][2][0], faces[1][2][0], faces[2][2][0], faces[4][0][2], reverse);
	}

	void rotateRight(bool reverse) {
		rotateFace(faces[3], reverse);
		swap(faces[4][2][0], faces[2][0][2], faces[1][0][2], faces[0][0][2], reverse);
		swap(faces[4][1][0], faces[2][1][2], faces[1][1][2], faces[0][1][2], reverse);
		swap(faces[4][0][0], faces[2][2][2], faces[1][2][2], faces[0][2][2], reverse);
	}

	void rotateUp(bool reverse) {
		rotateFace(faces[0], reverse);
		swap(faces[5][0][0], faces[4][0][0], faces[3][0][0], faces[1][0][0], reverse);
		swap(faces[5][0][1], faces[4][0][1], faces[3][0][1], faces[1][0][1], reverse);
		swap(faces[5][0][2], faces[4][0][2], faces[3][0][2], faces[1][0][2], reverse);
	}

	void rotateDown(bool reverse) {
		rotateFace(faces[2], reverse);
		swap(faces[1][2][0], faces[3][2][0], faces[4][2][0], faces[5][2][0], reverse);
		swap(faces[1][2][1], faces[3][2][1], faces[4][2][1], faces[5][2][1], reverse);
		swap(faces[1][2][2], faces[3][2][2], faces[4][2][2], faces[5][2][2], reverse);
	}

	void rotateFront(bool reverse) {
		rotateFace(faces[1], reverse);
		swap(faces[0][2][0], faces[3][0][0], faces[2][0][2], faces[5][2][2], reverse);
		swap(faces[0][2][1], faces[3][1][0], faces[2][0][1], faces[5][1][2], reverse);
		swap(faces[0][2][2], faces[3][2][0], faces[2][0][0], faces[5][0][2], reverse);
	}

	void rotateBack(bool reverse) {
		rotateFace(faces[4], reverse);
		swap(faces[5][2][0], faces[2][2][2], faces[3][0][2], faces[0][0][0], reverse);
		swap(faces[5][1][0], faces[2][2][1], faces[3][1][2], faces[0][0][1], reverse);
		swap(faces[5][0][0], faces[2][2][0], faces[3][2][2], faces[0][0][2], reverse);
	}
};

istream& operator>>(istream& is, RubiksCube& cube) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			is >> cube.faces[0][i][j];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			is >> cube.faces[1][i][j];
		for (int j = 0; j < 3; j++)
			is >> cube.faces[3][i][j];
		for (int j = 0; j < 3; j++)
			is >> cube.faces[4][i][j];
		for (int j = 0; j < 3; j++)
			is >> cube.faces[5][i][j];
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			is >> cube.faces[2][i][j];
	return is;
}

void print(vector<pair<char, bool>> actions, bool reverse) {
	for (auto p : actions) {
		cout << p.first;
		if (p.second != reverse)
			cout << '\'';
	}
	cout << endl;
} 

int main(int argc, char* argv[]) {
	RubiksCube cube;
	vector<pair<char, bool>> actions;
	srand(time(NULL));
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		bool reverse = rand() % 2 == 0;
		char rotation = rand() % 6;
		if (rotation == 0)
			rotation = 'L';
		else if (rotation == 1)
			rotation = 'R';
		else if (rotation == 2)
			rotation = 'U';
		else if (rotation == 3)
			rotation = 'D';
		else if (rotation == 4)
			rotation = 'F';
		else if (rotation == 5)
			rotation = 'B';
		if (rotation == 'L')
			cube.rotateLeft(reverse);
		else if (rotation == 'R')
			cube.rotateRight(reverse);
		else if (rotation == 'U')
			cube.rotateUp(reverse);
		else if (rotation == 'D')
			cube.rotateDown(reverse);
		else if (rotation == 'F')
			cube.rotateFront(reverse);
		else if (rotation == 'B')
			cube.rotateBack(reverse);
		actions.emplace_back(rotation, reverse);
	}
	print(actions, false);
	cout << string(cube) << endl;
	reverse(actions.begin(), actions.end());
	print(actions, true);
}
