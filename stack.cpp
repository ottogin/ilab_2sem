#define STARTSIZE 10
typedef data int;


class cstack
{
	private:
		data* a;
		int size;	
		int n;
	public:
		//constructors
		cstack() {}
		cstack(int s) {}
		cstack(const cstack& c) {}
		~cstack() {}

		//stack_functions
		void push(data x){}
		data pop(){}

		//service functions
		bool is_ok(){}
		void dump() {}
		
}


// constructors inint
cstack::cstack():
	n = 0;
	size = STARTSIZE;
{
        a = calloc(STARTSIZE);
}
cstak::cstack(int s):
        n = 0;
        size = s;
{
        a = malloc(s);
}
cstack::cstack(const cstack& c):
        size = c->size;
        n = c->n;
{
        a = calloc(c->size);
        for(int i = 0; i < c->n; i++)
        a[i] = c->a[i];
}
sctack::~cstack()
{
	free(a); 
	a = NULL;
	size = 0;
	n =  0;
} 


//  TODO stack function init

	 void push(data x){}
         data pop(){}

//  TODO service functions init

	bool is_ok(){}
        void dump() {}

