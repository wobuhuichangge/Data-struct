
#include"Stack.h"

test()
{
	Stack s;
	StackInit(&s);
	printf("%d %d\n", s._pos, s._array[s._pos-1]);
	StackPush(&s, 1); 
	printf("%d %d\n", s._pos, s._array[s._pos - 1]); 
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	printf("%d %d\n", s._pos, s._array[s._pos - 1]);
	StackPop(&s);
	printf("%d %d\n", s._pos, s._array[s._pos - 1]);

	StackPush(&s,5);
	printf("%d %d\n", s._pos, s._array[s._pos - 1]);
    StackDestory(&s);
	//printf("%d %d", s._pos, s._array[s._pos-1]);
}
int main()
{
	test();
	system("pause");
	return 0;
}