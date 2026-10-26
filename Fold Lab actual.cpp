
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;



template <typename T, typename Function>
int fold(T begin, T end, Function f) {
	T upcoming = begin;
	upcoming++;

	if (upcoming == end) {
		return*begin;
	}
	return f(*begin, fold(upcoming, end, f));
}

int add(int x, int y) {
	return x + y;
}

int multiply(int x, int y) {
	return x * y;
}

int divide(int x, int y) {
	return x / y;
}

int main()
{

	vector<int> ten = { 1,3,6 };
	vector<int> Single = { 67 };
	vector<int> two = { 3, 4 };

	vector<int> negative = { -1, -2, -3 };


	assert(fold(ten.begin(), ten.end(), add) == 10);
	assert(fold(Single.begin(), Single.end(), add) == 67);
	assert(fold(ten.begin(), ten.end(), multiply) == 18);
	assert(fold(ten.begin(), ten.end(), divide) == 2);
	assert(fold(negative.begin(), negative.end(), add) == -6);
	assert(fold(two.begin(), two.end(), add) == 7);


}


