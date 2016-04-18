#pragma once

#include<assert.h>

#define ASSERT(object)\
        if(!object->is_ok())\
        {\
                object->dump();\
                printf("Bad object in %s, in line %d, in file %s", __FUNCTION__, __LINE__, __FILE__);\
		exit(0);\
        }

