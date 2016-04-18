#include<stdio.h>
#include"logger.cpp"

enum 	NODE_TYPE{
	TYPE_UNKNOWN,
	TYPE_OPERATOR,
	TYPE_INTEGER,
	TYPE_FLOAT
};

union DATA{
	int i;
        float f;
};

class node
{
	private:
		NODE_TYPE _type;
                node* _left;
		node* _right;
                DATA _value;
	public:
		node();
		node(const node&);
		node(NODE_TYPE type, DATA value);
		~node();
		
		void add_left(node* list);
               	void add_left(NODE_TYPE type, DATA value);
                void add_right(node* list);
                void add_right(NODE_TYPE type, DATA value);
		node* operator+= (node* list);
		node* operator-= (node* list);
		static node* deep_copy (const node* list); 		
		
		void set_type(NODE_TYPE type);
		void set_value(DATA value);
		
		node* get_left() const;
		node* get_right() const;	
		DATA get_value() const;
		NODE_TYPE get_type() const;

		void calculate();

		void print_node()	const;
		void print()    const;
		void is_ok()	const;
};


node* getSpace(char*& s);
node* getExpression(char*& s);
node* getSum(char*& s);
node* getMul(char*& s);
node* getBrackets(char*& s);
node* getInt(char*& s);


class tree
{	
	private:
		node* _root;
		bool _initialized;
	public:
		tree();
		tree(const tree& t);
		~tree();
		
		tree* init_reverse();
		tree* init_parse(char* s);
		tree* init_calculate(tree* t);
		static node* create_tree_reverse();		
		static node* create_tree_parse(char* string); 	
		
		void calculate();

		void print()	const;
		void dump()	const;

		bool is_ok()	const;
		bool is_initialized()	const;		
		node* get_root() const;
};
