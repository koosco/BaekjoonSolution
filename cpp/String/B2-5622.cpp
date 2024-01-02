#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string input;
	int res = 0;
	cin >> input;
	
	for(const char c: input) {
		if(c == 'A' || c == 'B' || c == 'C')
			res += 2;
		else if(c == 'D' || c == 'E' || c == 'F')
			res += 3;
		else if(c == 'G' || c == 'H' || c == 'I')
			res += 4;
		else if(c == 'J' || c == 'K' || c == 'L')
			res += 5;
		else if(c == 'M' || c == 'N' || c == 'O')
			res += 6;
		else if(c == 'P' || c == 'Q' || c == 'R' || c == 'S')
			res += 7;
		else if(c == 'T' || c == 'U' || c == 'V')
			res += 8;
		else if(c == 'W' || c == 'X' || c == 'Y' || c == 'Z')
			res += 9;
		res++;
	}
	
	cout << res << endl;
    return 0;
}
