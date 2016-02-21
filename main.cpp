#include "stack.cpp"

int main()
{
	cstack a;
	a.dump();
	a.push(1);
	a.push(5);
	a.dump();
	printf("%d \n", a.pop());
	a.dump();
	return 0;
}
