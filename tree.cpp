#include "tree.h"


node::node ():
	_type(TYPE_UNKNOWN), _left(NULL), _right(NULL)	{	$1	_value.i = 0;	};
node::node(NODE_TYPE type, DATA value):
	_type(type), _value(value), _left(NULL), _right(NULL) {	$1	};
node::node(const node& copy)
{
	$1
	_type = copy.get_type();
	_value = copy.get_value();
 	_left = copy.get_left();
	_right = copy.get_right();	
};
node::~node()	{	$1	delete _left; delete _right;	};

void node::add_left(node* list)	{	$1	_left = list;	};
void node::add_left(NODE_TYPE type, DATA value)	{	$1	_left = new node(type, value);	};
void node::add_right(node* list)	{	$1	_right = list;	};
void node::add_right(NODE_TYPE type, DATA value)	{	$1	_right = new node(type, value);	};

void node::set_type(NODE_TYPE type)	{	$1	_type = type;	};
void node::set_value(DATA value)	{	$1	_value = value;	};

node* node::operator+=(node* list)	{	$1 add_right(list);	return this;	};
node* node::operator-=(node* list)	{	$1 add_left(list);	return this;	};
node* node::deep_copy(const node* list)	
{	
	$1
	node* new_node = new node();
	new_node->set_value(list->get_value());
	new_node->set_type(list->get_type());
	if(list->get_left()  != NULL)
		*new_node -= deep_copy(list->get_left());
	if(list->get_right() != NULL)
		*new_node += deep_copy(list->get_right());
	return new_node; 
};

node* node::get_left()	const 	{	$1	return _left;	};
node* node::get_right()	const 	{	$1	return _right;	};
DATA node::get_value()	const 	{	$1	return _value;	};
NODE_TYPE node::get_type()	const	{	$1	return _type;	};

void node::calculate()
{	
	$1
	if(_left == NULL || _right == NULL)
		return;	
	_left->calculate();
        _right->calculate();
	if( 	_left->get_type() == TYPE_INTEGER && _right->get_type() == TYPE_FLOAT  ) 
	{
		DATA val;
		val = _left->get_value();
		val.f = (float)val.i;
		_left->set_value(val);
		_left->set_type(TYPE_FLOAT);
	}
	if(   	_left->get_type() == TYPE_FLOAT   && _right->get_type() == TYPE_INTEGER)
	{
                DATA val;
                val = _right->get_value();
                val.f = (float)val.i;
                _right->set_value(val);
		_right->set_type(TYPE_FLOAT);
	}
	// Processing TYPE_INTEGER
	//
	//
	if(_left->get_type() == TYPE_INTEGER && _right->get_type() == TYPE_INTEGER)
	{
		DATA lv = _left->get_value();
                DATA rv = _right->get_value();
		DATA val;
		_type = TYPE_INTEGER;
		switch (_value.i)
		{
			case '+':
				val.i = lv.i + rv.i;
				break;
			case '-':
				val.i = lv.i - rv.i;
				break;
			case '*':
				val.i = lv.i * rv.i;
				break;
			case '/':
				val.i = lv.i / rv.i;
				break;
			case '%':
				val.i = lv.i % rv.i;
				break;
			default:
				$<<"Unknown operator";
				break;
		}
		delete _left;
		delete _right;
		_value = val;
		_left = NULL;
		_right = NULL;
	}
	//Processing TYPE_FLOAT
	//
	//
	else if(_left->get_type() == TYPE_FLOAT && _right->get_type() == TYPE_FLOAT)
        {
                DATA lv = _left->get_value();
                DATA rv = _right->get_value();
                DATA val;
                _type = TYPE_FLOAT;
                switch (_value.i)
                {
                        case '+':
                                val.f = lv.f + rv.f;
                                break;
                        case '-':
                                val.f = lv.f - rv.f;
                                break;
                        case '*':
                                val.f = lv.f * rv.f;
                                break;
                        case '/':
                                val.f = lv.f / rv.f;
                                break;
                        default:
                                $<<"Unknown operator";
				break;
                }
                delete _left;
                delete _right;
                _value = val;
                _left = NULL;
                _right = NULL;
        }

}	

void node::print_node()const
{
	$1
	switch (_type)
	{
		case TYPE_OPERATOR:	
			printf("%c", _value.i);
			break;
		case TYPE_INTEGER:
			printf("%d", _value.i);
			break;
		case TYPE_FLOAT:
			printf("%f", _value.f);
			break;
	}
};
void node::print()const
{
	$1
	if(_left != NULL)
		_left->print();
	print_node();
	if(_right != NULL)
		_right->print();
};
void node::is_ok()	const
{
	$1
	//TODO
};



tree::tree():
	_root(NULL), _initialized(false)	{	$1	};
tree::tree(const tree& t):
	_initialized(true)
{
	_root = node::deep_copy(t.get_root());	
};

tree::~tree()	{	$1 	delete _root;	};

node* tree::create_tree_reverse()
{
	$1
	DATA inp;
	node* new_node = new node();
	scanf("%c", (char*)&inp.i);
	if(inp.i == '+' || inp.i == '-')
	{
		new_node->set_type(TYPE_OPERATOR);
		new_node->set_value(inp);
		new_node->add_left(create_tree_reverse());
		new_node->add_right(create_tree_reverse());
	}		
	else	if(inp.i <= '9' && inp.i >= '0')
	{
		new_node->set_type(TYPE_INTEGER);
		inp.i -= '0';
		new_node->set_value(inp);
	}
	else
		new_node->set_type(TYPE_UNKNOWN);
	return new_node;
}

node* getSpace(char*& s)
{
	$1
	while(*s == ' ')
		s++;
	return NULL;	
}

node* getNumber(char*& s)
{
	$1
	DATA ans;
	ans.i = 0;
	node* new_node = new node(TYPE_INTEGER, ans);
	int counter = 0;
	bool got_smth = false;
	bool got_point = false;
	while((*s >= '0' && *s <= '9') || *s == '.')
	{
		if(*s == '.')
		{
			if(!got_smth || got_point)
				$<<"Unexpected expression.Bad number";
			s++;
			got_point = true;
			ans.f = (float)ans.i;
			counter++;	
		}
		else if(!got_point)
		{
			got_smth = true;
			ans.i *= 10;
			ans.i += *s - '0';
			s++;
		}
		else
		{	
			float addictive = *s - '0';
			for(int i = 0; i < counter; i++)
				addictive /= 10;
			counter++;
			ans.f += addictive;
			s++; 
		}
	}
	if(!got_smth)
		$<<"Unexpected expression. Expect number";
	if(got_point)
                new_node->set_type(TYPE_FLOAT);
	new_node->set_value(ans);
	getSpace(s);
	return new_node;
}

node* getBrackets(char*& s)
{
        $1
        if(*s == '(')
        {
                s++;
                getSpace(s);
                node* ret_node = getExpression(s);
                if(*s != ')')
                        $<<"Unexpexted expression. Bad bracket sequence";
                else
                        s++;
                getSpace(s);
                return ret_node;
        }
        return getNumber(s);
}


node* getMul(char*& s)
{
	$1
	node* ret_node = getBrackets(s);
        while(*s == '*' || *s == '/' || *s == '%')
        {
		DATA val;
		val.i = 0;
                node* new_node = new node(TYPE_OPERATOR, val);
		val.i = *s;
                new_node->set_value(val);
                *new_node -= ret_node;
                s++;
                getSpace(s);
                *new_node += getBrackets(s);
                ret_node = new_node;
        }
        return ret_node;	
}

node* getSum(char*& s)
{
	$1
	node* ret_node = getMul(s);
	while(*s == '+' || *s == '-')
	{
		DATA val;
                val.i = 0;
		node* new_node = new node(TYPE_OPERATOR, val);
		val.i = *s;
		new_node->set_value(val);
		*new_node -= ret_node;
		s++;
                getSpace(s);
        	*new_node += getMul(s);
		ret_node = new_node;
	}
	return ret_node;
}

node* getExpression(char*& s)
{
	$1
	return getSum(s);
}

node* tree:: create_tree_parse(char* s)
{
	$1
	node* new_node;
	getSpace(s);
	new_node = getExpression(s);
	if(*s != 0)
		$<<"Unexpected expressinon. Bad file ending";
	return new_node; 
}

tree* tree::init_parse(char *s)
{
	$1
	_root = create_tree_parse(s);
	_initialized = true;
}

tree* tree::init_reverse()
{	
	$1	
	_root = create_tree_reverse(); 
	_initialized = true;
};

tree* tree::init_calculate(tree* t)
{
	$1
	node* new_tree = new node();
	new_tree = node::deep_copy(t->get_root());
	_root = new_tree;
	_initialized = true;
	calculate();
};

void tree::calculate()
{
	$1
	_root->calculate();
}

void tree::print()const
{
	$1
	_root->print();	
	printf("\n");
};
void tree::dump()	const
{
	$1 
//TODO 
};

bool tree::is_ok()	const	
{
	$1
	//TODO
};
bool tree::is_initialized()const	{	$1	return _initialized;}
node* tree::get_root()	const 	{	$1	return _root;	};
