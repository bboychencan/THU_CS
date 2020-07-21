#include <iostream>
#include <fstream>
#include <cstring>
#include <thread>
#include <unistd.h>

using namespace std;

struct Time_t{
	int year; 
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

struct Log{
	Time_t tm;
	char id[20];
	char op[20];
};

struct Node{
	Log log;
	Node * next;
};

int Hash(const char * str){
	int res = 0;
	for(int i=0; i < strlen(str); i++){
		res ^= str[i];
	}
	return res;
}

void iterate_list(Node * head){
	int count = 0;
	while(head){
		cout << count << ' ' << head->log.id << endl;
		count ++;
		head = head->next;
	}
}
void delete_list(Node * head){
	cout << "delete list" << endl;
	while(head){
		Node * tmp = head;
		head = head->next;
		delete head;
	}
}

void Insert(Node * hash_tab[], Node elem){
	int idx = Hash(elem.log.id);
	Node * data = new Node;
	*data = elem;
	data->next = hash_tab[idx];
	hash_tab[idx] = data;
}

void Print(Node *list){
	while(list){
		cout << list->log.id << endl;
		list = list->next;
	}
}

void Output(Node *hash_tab[]){
	for(int i=0; i<256; i++){
		if(hash_tab[i] == NULL) continue;
		cout << i << ":";
		Print(hash_tab[i]);
		cout << endl << endl;
	}
}

void Delete(Node * list){
	while(list){
		Node * tmp = list;
		list = list->next;
		delete tmp;
	}
}

void Release(Node * hash_tab[]){
	for(int i=0; i<256; i++){
		if(hash_tab[i] == NULL) continue;
		Delete(hash_tab[i]);
		hash_tab[i] = NULL;
	}
}

void SaveHashTab(Node * hash_tab[], char* filename){
	ofstream fout(filename, ios::binary);
	for(int i=0; i<256; i++){
		Node *p = hash_tab[i];
		while(p){
			fout.write((char*) &(p->log), sizeof(p->log));
			p = p->next;
		}
	}
	fout.close();
}

void LoadHashTab(Node * hash_tab[], char * filename){
	ifstream fin(filename, ios::binary);
	while(fin){
		Node data;
		fin.read((char *) &data.log, sizeof(data.log));
		if(fin.eof())
			break;
		Insert(hash_tab, data);
	}
}

int main(){
	Node * hash_tab[256] = {NULL};
	// Node * head = new Node;


	// int count = 6;
	// while(count){
	// 	count --;
	// 	char tmp[count] = "hasdf";
	// 	cout << "tmp arr " << &tmp << endl;

	// }

	// ifstream fin("log.txt");

	// while(fin){
	// 	char tmp;
	// 	Node * data = new Node;
	// 	fin >> data ->log.tm. year >> tmp >> data->log.tm. month >> tmp >> data->log.tm.day;
	// 	fin >> data->log.tm.hour >> tmp >> data->log.tm.minute;
	// 	fin >> data->log.id;
	// 	fin >> data->log.op;

	// 	Insert(hash_tab, *data);
	// 	// data->next = head;
	// 	// head = data;
	// }
	char filename[] = "hash.tab";
	// SaveHashTab(hash_tab, filename);
	LoadHashTab(hash_tab, filename);
	Output(hash_tab);
	// Output(hash_tab);
	// Release(hash_tab);
	// fin.close();
	return 0;
}