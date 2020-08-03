#include <iostream>
#include <vector>
using namespace std;

int main(){
	unsigned a = ~0;
	for(int i = 0; i < 35; i ++){
		a <<= 1;
		cout << a << endl;;
	}

	return 0;
}