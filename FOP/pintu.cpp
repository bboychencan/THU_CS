#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <stdlib.h>
#include "my_function.h"

using namespace std;

int BLOCKS[1000000] = {0};
int PUZZLE[1000][1000] = {0};
unsigned int W = 0;
unsigned int H = 0;
unsigned int M;
unsigned int N;
int PX, PY; 
int bfType; 
BITMAPFILEHEADER bitMapFileHeader;
BITMAPINFOHEADER bitMapInfoHeader;
unsigned char * pic;

int main(int argc, char ** argv){
	string path;
	cout << "Please input bmp file path" << endl;
	cin >> path;

	cout << "start to load pic" << endl;
	load_picture(path, &pic);
	cout << "start to initialize" << endl;
	initialize();
	play();
	// save_picture();

	return 0;
}
