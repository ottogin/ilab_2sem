#include "stack.cpp"
#include "logger.cpp"

int main()
{
	$1
	cstack a(1);
	a.push(1);
	a.push(5);
	a.push(4);
	printf("%d \n", a.pop());
	printf("%d \n", a.get_back());
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	a.pop();
	return 0;
}
