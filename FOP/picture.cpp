#include <fstream>
#include "my_function.h"
using namespace std;

bool load_picture(string path, unsigned char** pic){
	ifstream fin(path, ios::binary);

	bfType;
	fin.read((char*) &bfType, sizeof(WORD));
	fin.read((char*) &bitMapFileHeader, sizeof(bitMapFileHeader));
	fin.read((char*) &bitMapInfoHeader, sizeof(bitMapInfoHeader));

	int w, h, fsize, biBitCount;
	fsize = bitMapFileHeader.bfSize;

	w = bitMapInfoHeader.biWidth;
	h = bitMapInfoHeader.biHeight;
	biBitCount = bitMapInfoHeader.biBitCount;

	unsigned char *temp = NULL;
	temp = new unsigned char[w*h*3];
	if(w > 0 && h > 0){
		for(int y = h-1; y >= 0; y--){
			for(int x = 0; x < w; x++){
				int i = (x + y * w) * 3;
				fin.read((char *) (temp + i), 3);
				// swap(temp[i], temp[i + 2]);
			}
		}
	}
	W = w;
	H = h;

	*pic = temp;
	fin.close();
	return true;
}

void save_picture(){
	//把没一块block对应的像素拼接起来
	//把bmp文件头写如二进制
	cout << "Please input save image path" << endl;
	string savepath; 
	cin >> savepath;
	ofstream fout(savepath + ".bmp", ios::binary);


	//test one block
	int blockheight = H / M;
	int blockwidth = W / N;
	int idx = 0;

	// bitMapInfoHeader.biWidth = blockwidth;
	// bitMapInfoHeader.biHeight = blockheight;

	cout << "biwidth is " << bitMapInfoHeader.biWidth << endl;
	cout << "biheight is " << bitMapInfoHeader.biHeight << endl;
	cout << "W is " << W << endl;
	cout << "H is " << H << endl;

	fout.write((char*) &bfType, sizeof(WORD));
	fout.write((char*) &bitMapFileHeader, sizeof(bitMapFileHeader));
	fout.write((char*) &bitMapInfoHeader, sizeof(bitMapInfoHeader));

	cout << "here" << endl;

	for(int y = H - 1; y >= 0; y --){
		int blockrow = y / blockheight; 
		if(y % blockheight == 0){
			// write boundary line;
			char temp[W] = {0};
			fout.write((char*) temp, W * 3);
		}
		for(int blockcol = 0; blockcol < N; blockcol ++){

			int order = PUZZLE[blockrow][blockcol];
			if(order == -1){
				char temp[blockwidth * 3] = {0};
				fout.write((char *) (&temp), 3 * blockwidth);
			}else{
				int new_blockcol = order % N;
				int new_y = (order / N) * blockheight + (y % blockheight);
				int i = (new_blockcol * blockwidth  + new_y * W) * 3; 
				char temp[1 * 3] = {0};
				fout.write((char *) (&temp), 3);
				fout.write((char *) (pic + i), 3 * (blockwidth - 1));
			}
			
		}
		
	}

	fout.close();
	cout << "Finished Saving Picture" << endl;
	display_puzzle();
}