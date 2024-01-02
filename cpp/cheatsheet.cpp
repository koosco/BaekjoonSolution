#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

int forEachSumofNum(int num) {
	int sum = 0;
	while(num != 0) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}