#include "stack.cpp"

int main()
{
	cstack a(1);
	a.dump();
	a.push(1);
	a.dump();
	a.push(5);
	a.dump();
	a.push(4);
	a.dump();
	printf("%d \n", a.pop());
	printf("%d \n", a.get_back());
	a.dump();
	a.pop();
	a.pop();
	a.dump();
	a.pop();
	a.pop();
	a.pop();
	return 0;
}
