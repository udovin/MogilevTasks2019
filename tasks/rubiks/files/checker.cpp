#include "testlib.h"
#include <vector>

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

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);
	stringstream ss;
	for (int i = 0; i < 9; i++)
		ss << inf.readLine() << endl;
	RubiksCube cube;
	ss >> cube;
	string rotations = ouf.readLine("[LRUDFB']{1,200000}");
	int k = 0;
	for (int i = 0; i < rotations.size(); i++, k++) {
		if (k == 100000)
			quitf(_wa, "Too many rotations");
		bool reverse = false;
		if (i + 1 < rotations.size() && rotations[i + 1] == '\'')
			reverse = true;
		if (rotations[i] == 'L')
			cube.rotateLeft(reverse);
		else if (rotations[i] == 'R')
			cube.rotateRight(reverse);
		else if (rotations[i] == 'U')
			cube.rotateUp(reverse);
		else if (rotations[i] == 'D')
			cube.rotateDown(reverse);
		else if (rotations[i] == 'F')
			cube.rotateFront(reverse);
		else if (rotations[i] == 'B')
			cube.rotateBack(reverse);
		else
			quitf(_wa, "Invalid rotation");
		if (reverse)
			i++;
	}
	int score = cube.getScore();
	if (score == 48)
		quitf(_ok, "Full solution");
	quitp(9 * static_cast<double>(score) / 48);
}
