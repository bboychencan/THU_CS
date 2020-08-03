#include <iostream>
using namespace std;

int main(){
	std::srand((unsigned) std::time(0));

	int total_service_time = 240;
	int window_num = 4;
	int simulate_num = 100000;

	QueueSystem system(total_service_time, window_num);
	system.simulate_num(simulate_num);

	cout << "The average waiting time is " << system.getAvgStatyTime() << endl;
	cout << "The number of arring customers per minute " << system.getAvgCustomers() << endl;

	return 0;
}