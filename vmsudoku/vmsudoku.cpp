#include <bits/stdc++.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#define UNASSIGNED 0

using namespace std;

class Sudoku {
	private:
		int grid[9][9];
		int solnGrid[9][9];
		int guessNum[9];
		int gridPos[81];
		int difficultyLevel;
		bool grid_status;

	public:
		Sudoku ();
		Sudoku (string, bool row_major=true);
		void fillEmptyDiagonalBox(int);
		void createSeed();
		void printGrid();
		bool solveGrid();
		string getGrid();
		void countSoln(int &number);
		void genPuzzle();
		bool verifyGridStatus();
		void printSVG(string);
		void calculateDifficulty();
		int  branchDifficultyScore();
};

// START: Get grid as string in row major order
string Sudoku::getGrid() {
	string s = "";
	for(int row_num=0; row_num<9; ++row_num) {
		for(int col_num=0; col_num<9; ++col_num) {
			s = s + to_string(grid[row_num][col_num]);
		}
	}

	return s;
}
// END: Get grid as string in row major order


// START: Generate random number
int genRandNum(int maxLimit) {
	return rand()%maxLimit;
}
// END: Generate random number


// START: Helper functions for solving grid
bool FindUnassignedLocation(int grid[9][9], int &row, int &col) {
	for (row = 0; row < 9; row++) {
		for (col = 0; col < 9; col++) {
			if (grid[row][col] == UNASSIGNED)
				return true;
		}
	}

	return false;
}

bool UsedInRow(int grid[9][9], int row, int num) {
	for (int col = 0; col < 9; col++) {
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool UsedInCol(int grid[9][9], int col, int num) {
	for (int row = 0; row < 9; row++) {
		if (grid[row][col] == num)
			return true;
	}

	return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (grid[row+boxStartRow][col+boxStartCol] == num)
				return true;
		}
	}

	return false;
}

bool isSafe(int grid[9][9], int row, int col, int num) {
	return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row%3, col - col%3, num);
}
// END: Helper functions for solving grid


// START: Create seed grid
void Sudoku::fillEmptyDiagonalBox(int idx) {
	int start = idx*3;
	random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			this->grid[start+i][start+j] = guessNum[i*3+j];
		}
	}
}

void Sudoku::createSeed() {
	/* Fill diagonal boxes to form:
	    x | . | .
	    . | x | .
	    . | . | x
	*/
	this->fillEmptyDiagonalBox(0);
	this->fillEmptyDiagonalBox(1);
	this->fillEmptyDiagonalBox(2);

	/* Fill the remaining blocks:
	    x | x | x
	    x | x | x
	    x | x | x
	*/
	this->solveGrid(); // TODO: not truly random, but still good enough because we generate random diagonals.

	// Saving the solution grid
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			this->solnGrid[i][j] = this->grid[i][j];
		}
	}
}
// END: Create seed grid


// START: Intialising
Sudoku::Sudoku() {

	// initialize difficulty level
	this->difficultyLevel = 0;

	// Randomly shuffling the array of removing grid positions
	for(int i=0; i<81; i++) {
		this->gridPos[i] = i;
	}

	random_shuffle(this->gridPos, (this->gridPos) + 81, genRandNum);

	// Randomly shuffling the guessing number array
	for(int i=0; i<9; i++) {
		this->guessNum[i]=i+1;
	}

	random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);

	// Initialising the grid
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			this->grid[i][j]=0;
		}
	}

	grid_status = true;
}
// END: Initialising


// START: Custom Initialising with grid passed as argument
Sudoku::Sudoku(string grid_str, bool row_major) {
	if(grid_str.length() != 81) {
		grid_status=false;
		return;
	}

	// First pass: Check if all cells are valid
	for(int i=0; i<81; ++i) {
		int curr_num = grid_str[i]-'0';
		if(!((curr_num == UNASSIGNED) || (curr_num > 0 && curr_num < 10))) {
			grid_status=false;
			return;
		}

		if(row_major) grid[i/9][i%9] = curr_num;
		else          grid[i%9][i/9] = curr_num;
	}

	// Second pass: Check if all columns are valid
	for (int col_num=0; col_num<9; ++col_num) {
		bool nums[10]= {false};
		for (int row_num=0; row_num<9; ++row_num) {
			int curr_num = grid[row_num][col_num];
			if(curr_num!=UNASSIGNED && nums[curr_num]==true) {
				grid_status=false;
				return;
			}
			nums[curr_num] = true;
		}
	}

	// Third pass: Check if all rows are valid
	for (int row_num=0; row_num<9; ++row_num) {
		bool nums[10]= {false};
		for (int col_num=0; col_num<9; ++col_num) {
			int curr_num = grid[row_num][col_num];
			if(curr_num!=UNASSIGNED && nums[curr_num]==true) {
				grid_status=false;
				return;
			}
			nums[curr_num] = true;
		}
	}

	// Fourth pass: Check if all blocks are valid
	for (int block_num=0; block_num<9; ++block_num) {
		bool nums[10]= {false};
		for (int cell_num=0; cell_num<9; ++cell_num) {
			int curr_num = grid[((int)(block_num/3))*3 + (cell_num/3)][((int)(block_num%3))*3 + (cell_num%3)];
			if(curr_num!=UNASSIGNED && nums[curr_num]==true) {
				grid_status=false;
				return;
			}
			nums[curr_num] = true;
		}
	}

	// Randomly shuffling the guessing number array
	for(int i=0; i<9; i++) {
		this->guessNum[i]=i+1;
	}

	random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);

	grid_status = true;
}
// END: Custom Initialising


// START: Verification status of the custom grid passed
bool Sudoku::verifyGridStatus() {
	return grid_status;
}
// END: Verification of the custom grid passed

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

#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define fi first
#define se second
// START: Printing the grid
int ans = 0;
bool work = false;
void Sudoku::printGrid() {
	int a[19][19];
    vector<pair<int, int>> g[19];
	Answer = false;
	for(int i = 0; i < 9; i++)
		for(int j = 1; j <= 9; j++)
			Row[i][j] = Col[i][j] = 0;

	// Nh?p vào ma tr?n
	// d?ng th?i ki?m luu tr?ng thái các s? dã có hay chua t?i t?ng hàng, c?t
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++) {
			Matrix[i][j] = grid[i][j];

			// T?i dòng i, s? có giá tr? tmp dã xu?t hi?n
			Row[i][grid[i][j]] = true;
			// T?i c?t j, s? có giá t? tmp dã xu?t hi?n
			Col[j][grid[i][j]] = true;
		}

	// B?t d?u xét t? ô d?u tiên hàng = 0 và c?t = 0
	Check(0, 0);

	// In k?t qu?
	//if(Answer) {
	//}
	FOR(i, 0, 8) {
		FOR(j, 0, 8) {
			g[Matrix[i][j]].push_back({i, j});
		}
	}
	ans = 0;
	FOR(i, 1, 9) {
		int sum_i = 0;
		FOR(j, 0, g[i].size() - 2) {
			FOR(z, j + 1, g[i].size() - 1) {
				sum_i += abs(g[i][z].fi -g[i][j].fi) * abs(g[i][z].se -g[i][j].se);
			}
		}
		ans += sum_i * i;
	}
	ans -= 17000;
	ans = max(ans, 0);
	ans = min(ans, 1062);
	if(ans > 1000) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				cout << Matrix[i][j];
			cout << endl;
		}
		cout << ans;
		work = true;
	}
}


// START: Modified Sudoku solver
bool Sudoku::solveGrid() {
	int row, col;

	// If there is no unassigned location, we are done
	if (!FindUnassignedLocation(this->grid, row, col))
		return true; // success!

	// Consider digits 1 to 9
	for (int num = 0; num < 9; num++) {
		// if looks promising
		if (isSafe(this->grid, row, col, this->guessNum[num])) {
			// make tentative assignment
			this->grid[row][col] = this->guessNum[num];

			// return, if success, yay!
			if (solveGrid())
				return true;

			// failure, unmake & try again
			this->grid[row][col] = UNASSIGNED;
		}
	}

	return false; // this triggers backtracking

}
// END: Modified Sudoku Solver


// START: Check if the grid is uniquely solvable
void Sudoku::countSoln(int &number) {
	int row, col;

	if(!FindUnassignedLocation(this->grid, row, col)) {
		number++;
		return ;
	}


	for(int i=0; i<9 && number<2; i++) {
		if( isSafe(this->grid, row, col, this->guessNum[i]) ) {
			this->grid[row][col] = this->guessNum[i];
			countSoln(number);
		}

		this->grid[row][col] = UNASSIGNED;
	}

}
// END: Check if the grid is uniquely solvable


// START: Gneerate puzzle
void Sudoku::genPuzzle() {
	for(int i=0; i<81; i++) {
		int x = (this->gridPos[i])/9;
		int y = (this->gridPos[i])%9;
		int temp = this->grid[x][y];
		this->grid[x][y] = UNASSIGNED;

		// If now more than 1 solution , replace the removed cell back.
		int check=0;
		countSoln(check);
		if(check!=1) {
			this->grid[x][y] = temp;
		}
	}
}
// END: Generate puzzle


// START: Printing into SVG file
void Sudoku::printSVG(string path="") {
	string fileName = path + "svgHead.txt";
	ifstream file1(fileName.c_str());
	stringstream svgHead;
	svgHead << file1.rdbuf();

	ofstream outFile("puzzle.svg");
	outFile << svgHead.rdbuf();

	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(this->grid[i][j]!=0) {
				int x = 50*j + 16;
				int y = 50*i + 35;

				stringstream text;
				text<<"<text x=\""<<x<<"\" y=\""<<y<<"\" style=\"font-weight:bold\" font-size=\"30px\">"<<this->grid[i][j]<<"</text>\n";

				outFile << text.rdbuf();
			}
		}
	}

	outFile << "<text x=\"50\" y=\"500\" style=\"font-weight:bold\" font-size=\"15px\">Difficulty Level (0 being easiest): "                  <<this->difficultyLevel<<"</text>\n";
	outFile << "</svg>";

}
// END: Printing into SVG file


// START: Calculate branch difficulty score
int Sudoku::branchDifficultyScore() {
	int emptyPositions = -1;
	int tempGrid[9][9];
	int sum=0;

	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			tempGrid[i][j] = this->grid[i][j];
		}
	}

	while(emptyPositions!=0) {
		vector<vector<int> > empty;

		for(int i=0; i<81; i++) {
			if(tempGrid[(int)(i/9)][(int)(i%9)] == 0) {
				vector<int> temp;
				temp.push_back(i);

				for(int num=1; num<=9; num++) {
					if(isSafe(tempGrid,i/9,i%9,num)) {
						temp.push_back(num);
					}
				}

				empty.push_back(temp);
			}

		}

		if(empty.size() == 0) {
			cout<<"Hello: "<<sum<<endl;
			return sum;
		}

		int minIndex = 0;

		int check = empty.size();
		for(int i=0; i<check; i++) {
			if(empty[i].size() < empty[minIndex].size())
				minIndex = i;
		}

		int branchFactor=empty[minIndex].size();
		int rowIndex = empty[minIndex][0]/9;
		int colIndex = empty[minIndex][0]%9;

		tempGrid[rowIndex][colIndex] = this->solnGrid[rowIndex][colIndex];
		sum = sum + ((branchFactor-2) * (branchFactor-2)) ;

		emptyPositions = empty.size() - 1;
	}

	return sum;

}
// END: Finish branch difficulty score


// START: Calculate difficulty level of current grid
void Sudoku::calculateDifficulty() {
	int B = branchDifficultyScore();
	int emptyCells = 0;

	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			if(this->grid[i][j] == 0)
				emptyCells++;
		}
	}

	this->difficultyLevel = B*100 + emptyCells;
}
// END: calculating difficulty level


// START: The main function
int main(int argc, char const *argv[]) {
	// Initialising seed for random number generation
	while(work == false) {
		srand(time(NULL));
		ans = 0;
		// Creating an instance of Sudoku
		Sudoku *puzzle = new Sudoku();

		// Creating a seed for puzzle generation
		puzzle->createSeed();

		// Generating the puzzle
		puzzle->genPuzzle();

		// Calculating difficulty of puzzle
//	puzzle->calculateDifficulty();

		// testing by printing the grid
		puzzle->printGrid();
		delete puzzle;
	}
	// Printing the grid into SVG file
//	string rem = "sudokuGen";
//	string path = argv[0];
//	path = path.substr(0,path.size() - rem.size());
//	puzzle->printSVG(path);
	return 0;
}
// END: The main function
