// �ð� �ʰ�
// N^4 �� ���� �����ɸ�;;
// ��ĭ�� ȭ��Ʈĭ�� �����Ͽ� ������ ��...

#include <iostream>

#define BLOCK 0
#define BLANK 1
#define PIECE 2

using namespace std;

int diagBoard[20][20];
pair<int, int> origin;
int boardSize = 0;
int diagSize = 0;

int answer = 0;

bool isSafeToPlay(int r, int c) {
	int diagR = origin.first + r + c;
	int diagC = origin.second + r - c;

	for (int row = 0; row < diagSize; ++row) {
		if (row == diagR) {
			for (int col = 0; col < diagSize; ++col) {
				if (diagBoard[row][col] == PIECE) return false;
			}
		}
		else if (diagBoard[row][diagC] == PIECE) return false;
	}

	return true;
}

void playBishop(int r, int c, int numOfBishop) {
	if (c >= boardSize) {
		r++;
		c -= boardSize;
	}

	if (r >= boardSize) {
		answer = max(answer, numOfBishop);
		
		return;
	}

	for (int row = r; row < boardSize; ++row) {
		for (int col = c; col < boardSize; ++col) {
			// ���� ��ǥ�迡�� �밢 ��ǥ��� ��ȯ
			int diagR = origin.first + row + col;
			int diagC = origin.second + row - col;

			// �ش� ĭ�� ���� ����� ���� �� ���� �ڸ����
			if (diagBoard[diagR][diagC] != BLANK) continue;
				
			if (isSafeToPlay(row, col)) {
				// �ش� ĭ�� ����� ���� �� �ִ� �ڸ����			
				diagBoard[diagR][diagC] = PIECE;
				playBishop(row, col + 1, numOfBishop + 1);
				diagBoard[diagR][diagC] = BLANK;
			}
		}
	}
}

int main() {
	cin >> boardSize;
	diagSize = 2 * boardSize - 1;
	origin = make_pair(0, boardSize - 1);

	for (int row = 0; row < boardSize; ++row) {
		for (int col = 0; col < boardSize; ++col) {
			cin >> diagBoard[origin.first + row + col][origin.second + row - col];
		}
	}

	playBishop(0, 0, 0);
	cout << answer << "\n";
}