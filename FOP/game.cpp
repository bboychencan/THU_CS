#include <algorithm>
#include <random>
#include <string>

using namespace std;
#include "my_function.h"

void initialize(){
	cout << "Please input the difficulty: M N " << endl;
	cin >> M >> N;
	for(int i = 0; i < M * N - 1; i++){
		BLOCKS[i] = i;
	}
	BLOCKS[M * N - 1] = -1;
	int idx = 0;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			PUZZLE[i][j] = BLOCKS[idx];
			idx ++;
		}
	}
	PX = M - 1;
	PY = N - 1;
	randomize();
}

void randomize(){
	unsigned seed = 0;
	shuffle(BLOCKS, BLOCKS + M * N,  default_random_engine(seed));
	int idx = 0;

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
				if(BLOCKS[idx] == -1){
					PX = i;
					PY = j;
				}
				PUZZLE[i][j] = BLOCKS[idx];
				idx ++;
			}
	}
	display_puzzle();

	if(solvable()){
		cout << "This layout is solvable. " << endl;
		
	}else{
		cout << "Not solvable, please generate new layout. "<< endl;
	}
}

void display_puzzle(){
	cout << "Display Puzzle : " << endl;
	printf("\n");
	for(int i=0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%4d", PUZZLE[i][j]);
		}
		printf("\n");
	}
	// cout << "Compressed status is " << compress_status(BLOCKS, sizeof(BLOCKS));
	printf("\n");
}

void display_guide(){
	cout << "=================Operation Guide====================" << endl;
	cout << "p:	" << "exit" << endl;
	cout << "r:	" << "reshuffle blocks" << endl;
	cout << "g:	" << "Save picture" << endl;
	cout << "f:	" << "Auto solve" << endl;
	cout << "i:	" << "Temp save status" << endl;
	cout << "=================Operation Guide====================" << endl;
	cout << endl;
	return;
}


void save_status(){

}

void load_status(){
	cout << "Current saves are : " << endl;
	string savename = "";
	cin >> savename;
	return;
}

void play(){
	display_guide();
	display_puzzle();
	char command;
	while(cin >> command){
		switch(command){
			case 's':
				if(PX > 0){
					swap(PUZZLE[PX][PY], PUZZLE[PX - 1][PY]);
					PX = PX - 1;
				}
				display_puzzle();
				if(check_puzzle_status()){
					cout << "CONGRADUATIONS!" << endl;
				}
				break;
			case 'w':
				if(PX < M - 1){
					swap(PUZZLE[PX][PY], PUZZLE[PX + 1][PY]);
					PX = PX + 1;
				}
				display_puzzle();
				if(check_puzzle_status()){
					cout << "CONGRADUATIONS!" << endl;
				}
				break;
			case 'd':
				if(PY > 0){
					swap(PUZZLE[PX][PY], PUZZLE[PX][PY - 1]);
					PY = PY - 1;
				}
				display_puzzle();
				if(check_puzzle_status()){
					cout << "CONGRADUATIONS!" << endl;
				}
				break;
			case 'a':
				if(PY < N - 1){
					swap(PUZZLE[PX][PY], PUZZLE[PX][PY + 1]);
					PY = PY + 1;
				}
				if(check_puzzle_status()){
					cout << "CONGRADUATIONS!" << endl;
				}
				display_puzzle();
				break;
			case 'r':
				randomize();
				break;
			case 'g':
				cout << "Save picture" << endl;
				save_picture();
				break;
			case 'i':
				cout << "Temp save status" << endl;
				break;
			case 'o':
				cout << "Load status" << endl;
				load_status();
				break;
			case 'p':
				cout << "Bye" << endl;
				return;
			case 'f':
				cout << "Auto solve" << endl;
				break;
		}
	}
}
