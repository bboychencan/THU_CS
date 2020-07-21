#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <stdlib.h>

using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

struct BITMAPFILEHEADER{
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
} bitMapFileHeader;

struct BITMAPINFOHEADER{
	DWORD biSize;
	DWORD biWidth;
	DWORD biHeight;	
	WORD biPlanes;
	WORD biBitCount;
	DWORD biCompression;
	DWORD biSizeImage;
	DWORD biXPelsPerMeter;
	DWORD biYPelsPerMeter;
	DWORD biClrUsed;
	DWORD biClrImportant;
} bitMapInfoHeader; 

bool load_picture(char* path){

	ifstream fin(path, ios::binary);

	int bfType;
	fin.read((char*) &bfType, sizeof(WORD));
	fin.read((char*) &bitMapFileHeader, sizeof(bitMapFileHeader));
	fin.read((char*) &bitMapInfoHeader, sizeof(bitMapInfoHeader));

	// printf("%x", bitMapFileHeader.bfSize[1]);
	// printf("%x", bitMapFileHeader.bfSize[2]);
	// printf("%x", bitMapFileHeader.bfSize[3]);

	int w, h, fsize, biBitCount;
	fsize = bitMapFileHeader.bfSize;

	w = bitMapInfoHeader.biWidth;
	h = bitMapInfoHeader.biHeight;
	biBitCount = bitMapInfoHeader.biBitCount;

	cout << "bisize " << bitMapInfoHeader.biSize;
	cout << "fsize : " << fsize << endl;
	cout << "width : " << w << endl;
	cout << "height : " << h << endl;
	cout << "biBitCount : " << biBitCount << endl;
	
	// cout << "fsize is " << bitMapFileHeader.bfSize << endl;

	fin.close();
	return true;
}


int main(int argc, char ** argv){
	char * path;
	path = argv[1];
	cout << "file path is " << path << endl;

	load_picture(path);
	// load_picture_2(path);

	return 0;
}