#include <iostream>
using namespace std;

extern unsigned int W;
extern unsigned int H;
extern unsigned int M;
extern unsigned int N;
extern int PX, PY; 
extern unsigned char * pic;
extern int BLOCKS[1000000];
extern int PUZZLE[1000][1000];
extern int bfType; 

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;



struct BITMAPFILEHEADER{
	DWORD bfSize;
	WORD bfReserved1;
	WORD bfReserved2;
	DWORD bfOffBits;
} ;

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
} ; 

extern BITMAPFILEHEADER bitMapFileHeader;
extern BITMAPINFOHEADER bitMapInfoHeader;


void randomize();
void display_guide();
void display_puzzle();
void window();
void initialize();
void play();
bool check_puzzle();
bool check_puzzle_status();
bool solvable();
int count_reverse();
bool load_picture(string path, unsigned char** pic);
void save_picture();
string compress_status(unsigned int* sequence, int size);

