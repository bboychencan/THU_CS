#include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

int count;

extern void write_extern();

int main(){
	count = 5;
	write_extern();

	return 0;
}