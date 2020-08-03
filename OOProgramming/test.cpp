#include <iostream>
using namespace std;

class Matrix{
	int id;
public:
	void test(){
		return;
	}
	friend void print(Matrix x);
};

void print(int a){
	cout << a << endl;
}

void print(char * s){
	cout << s << endl;
}

void print(Matrix obj){
	cout << obj.id << endl;
}




int main(){
	auto i = 3;
	int arr[10] = {0};

	Matrix* a = new Matrix;
	print(*a);
	return 0;
}