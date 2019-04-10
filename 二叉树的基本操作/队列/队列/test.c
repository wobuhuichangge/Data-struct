
#include "Queue.h"

void TestQueue()
{
	Queue s;
	int ret = 0;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePop(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
	//QueuePop(&s);
	//QueuePop(&s);
	//QueuePop(&s);
	//ret = QueueFront(&s);
	//ret = QueueBack(&s);
	//ret = QueueEmpty(&s);
	ret = QueueSize(&s);
}
int main()
{

    TestQueue();
	system("pause");
	return 0;
}