#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int>, vector<int>);
int gcd(int a, int b);
int condCase(vector<int>, vector<int>);

int main() {
	vector<int> arrayA = { 2 };
	vector<int> arrayB = { 8 };

	cout << solution(arrayA, arrayB);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;
	int cDivisor = 0;

	cDivisor = condCase(arrayA, arrayB) > condCase(arrayB, arrayA) ? condCase(arrayA, arrayB) : condCase(arrayB, arrayA);
	answer = cDivisor;

	return answer;
}

// �ִ� ����� ���ϱ�
int gcd(int a, int b) {
	// ��Ŭ���� ȣ����
	int dividend = a;
	int divisor = b;
	int r = dividend % divisor;
	while (r != 0) {
		dividend = divisor;
		divisor = r;
		r = dividend % divisor;
	}

	return divisor;
}

int condCase(vector<int> array1, vector<int> array2) {
	int cDivisor = array1[0];	
	if (array1.size() > 1) {	// array1�� ũ�Ⱑ 2�� �̻��� ��� �ִ����� ���ϱ�
		cDivisor = gcd(array1[0], array1[1]);

		for (int i = 2; i < array1.size(); i++) {
			cDivisor = gcd(cDivisor, array1[i]);
		}
	}
	

	// array2 �� ��� ��Ҹ� ������ ������ ��
	for (int i : array2) {
		if (i % cDivisor == 0)
			return 0;
	}


	return cDivisor;
}

