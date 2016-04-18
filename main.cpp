#include <iostream>
#include <stdlib.h>


//#include "stack.cpp"
#include "logger.cpp"
//#include "CVector.cpp"
#include "tree.cpp"

int main()
{
	$1
	tree a;
	FILE* in = fopen("file_to_parse.txt", "r");
	char* s = (char*)malloc(1000);
	char* it = s;
	while(fscanf(in, "%c", it) != EOF)
		it++;
	a.init_parse(s);
	a.print();
	tree b;
	b.init_calculate(&a);
	b.print();
	fclose(in);
	free(s);
	return 0;
}
