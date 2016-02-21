#define STARTSIZE 10    //determines which what size will be created stack whith defoult constructor
#define SIZEINC 2       //determines how many times will increase the stack size 
typedef int DATA;       //type of stack's elements

class cstack
{
        private:
                DATA * a;
                int size;
                int n;
        public:
                //constructors
                cstack();
                cstack(int s);
                cstack(const cstack& c);
                ~cstack();
		
		//operators
		cstack operator=(const cstack& c);
	
                //stack_functions
                void push(DATA x);
                DATA pop();
                DATA get_back();

                //service functions
                bool is_ok();
                void dump();
                bool is_empty();

                //get-functions
                int get_size();
                int get_num();
                DATA get_element(int i);
};
