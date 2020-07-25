#include <iostream>
#include <string>
#include "my_function.h"

int count_reverse();

bool solvable(){
	int count = count_reverse();
	cout << "reverse count is " << count << endl;
	if(count % 2 == 0){
		return true;
	}else{
		return false;
	}
}

string compress_status(unsigned int* sequence, int size){
	string status = "";
	for(int i = 0; i < size; i++){
		if(sequence[i] == -1){
			status += to_string(0);
		}else{
			status += to_string(sequence[i]);
		}
		
	}
	cout << "status is " << status << endl;
	return status;
}

int count_reverse(){
	// 暴力解法
	int count = 0;
	for(int i = 0; i < M * N; i ++){
		if(BLOCKS[i] == -1) continue;

		for(int j = 0; j < i; j ++){
			if(BLOCKS[j] == -1) continue;
			// cout << "block item is " << BLOCKS[i] << " " << BLOCKS[j] << " count is " << count << endl;
			if(BLOCKS[j] > BLOCKS[i]){
				count += 1;
			} 
		}
	}
	if(N % 2 == 0){
		int dist;
		dist = (PX - (N - 1));
		count += dist;
	}
	

	// merge sort 方法
	// int count = 0;

	return count;
}

bool check_puzzle_status(){
	int cur = 0;
	
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(i == M - 1 && j == N - 1) continue;
			if(PUZZLE[i][j] != cur){
				return false;
			}else{
				cur ++;
				continue;
			}
		}
	}
	if(PUZZLE[M - 1][N - 1] == -1) return true;
	else return false;
}

void bfs(){

}

void astar(){
	

}

string solve(){
	char* solution[100];

	return NULL;
}