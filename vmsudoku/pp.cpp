#include<iostream>
using namespace std;

// Luu ma tr?n suduku
int Matrix[9][9];

// K?t qu? bài toán, Answer = true => có gi?i pháp, Answer = false nghia là không có
bool Answer;

// Luu tr?ng thái t?i t?ng hàng, c?t t? 0 d?n 9, các s? t? 1 d?n 9 dã có chua
bool Row[9][10], Col[9][10];

void Next(int &row, int &col) {
	if(col < 8) col++;
	else {
		col = 0;
		row++;
	}
}

bool IsValid(int row, int col, int value) {
	// Ki?m tra xem t?i c?t dang xét, giá tr? 'value' này dã có chua
	if(Col[col][value] == true) return false;

	// Ki?m tra xem t?i hàng dang xét, giá tr? 'value' này dã có chua
	if(Row[row][value] == true) return false;

	// Ki?m tra xem trong kh?i nh? 3x3 dã có giá tr? 'value' hay chua
	int sr = row - row % 3;
	int sc = col - col % 3;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(Matrix[i + sr][j + sc] == value) return false;

	return true;
}

void Check(int row, int col) {
	// N?u di du?c h?t các dòng thì có nghia là dã có gi?i pháp
	if(row == 9) {
		Answer = true;
		return;
	}

	// N?u t?i ô dó dã có giá tr? khác 0 thì ta s? ki?m tra d?n ô ti?p theo
	if (Matrix[row][col] != 0) {
		Next(row, col);
		Check(row, col);
	} else { // N?u ô dó = 0 thì b?t d?u di?n th? giá tr? t? 1 d?n 9
		int old_row, old_col;

		for(int i = 1; i <= 9; i++) {
			// Ki?m tra xem n?u ô t?i hàng row, và c?t col,
			// di?n giá tr? i có h?p l? không. N?u h?p l? thì di?n th?
			if(IsValid(row, col, i)) {
				old_row = row;
				old_col = col;

				Matrix[row][col] = i;
				Row[row][i] = true;
				Col[col][i] = true;
				Next(row,col);

				Check(row,col);

				if(Answer) return;

				row = old_row;
				col = old_col;
				Row[row][i] = false;
				Col[col][i] = false;
				Matrix[row][col] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	Answer = false;
	for(int i = 0; i < 9; i++)
		for(int j = 1; j <= 9; j++)
			Row[i][j] = Col[i][j] = 0;

	// Nh?p vào ma tr?n
	// d?ng th?i ki?m luu tr?ng thái các s? dã có hay chua t?i t?ng hàng, c?t
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++) {
			int tmp;
			cin >> tmp;
			Matrix[i][j] = tmp;

			// T?i dòng i, s? có giá tr? tmp dã xu?t hi?n
			Row[i][tmp] = true;
			// T?i c?t j, s? có giá t? tmp dã xu?t hi?n
			Col[j][tmp] = true;
		}

	// B?t d?u xét t? ô d?u tiên hàng = 0 và c?t = 0
	Check(0, 0);

	// In k?t qu?
	if(Answer) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				cout << Matrix[i][j] << " ";
			cout << endl;
		}
	} else cout << "No solution" << endl;

	return 0;
}