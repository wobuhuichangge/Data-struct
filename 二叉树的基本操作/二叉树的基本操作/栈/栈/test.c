
#include"Stack.h"

test()
{
	Stack s;
	int ret = -1;
	StackInit(&s);
	ret = StackEmpty(&s);
	printf("%d\n", ret);
	//printf("%d %d\n", s._pos, s._array[s._pos-1]);
	StackPush(&s, 1); 
	//printf("%d %d\n", s._pos, s._array[s._pos - 1]); 
	StackPush(&s, 2);
	printf("%d\n", StackTop(&s));
	StackPush(&s, 3);
	StackPush(&s, 4);
	//printf("%d %d\n", s._pos, s._array[s._pos - 1]);
	StackPop(&s);
	//printf("%d %d\n", s._pos, s._array[s._pos - 1]);

	StackPush(&s,5);
	printf("%d %d\n", s._pos, s._array[s._pos - 1]);
    StackDestroy(&s);
	//printf("%d %d", s._pos, s._array[s._pos-1]);
}
int main()
{
	test();
	system("pause");
	return 0;
}