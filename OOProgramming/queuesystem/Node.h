struct Node{
	int arrive_time;
	int duration;
	struct Node* next;

	Node(int arrive_time = 0, int duration = Random::uniform(RANDOM_PARAMETER)):
		arrive_time(arrive_time),
		duration(duration),
		next(NULL) {}
};

typedef struct Node Node;
typedef struct Node Customer;