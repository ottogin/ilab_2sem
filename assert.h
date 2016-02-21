#pragma once

#include<assert.h>

# define ASSERT(object, adress)\
        if(!object->is_ok())\
        {\
                object->dump();\
                assert(!"Error in " #adress);\
        }\

