#pragma once

#include <stdio.h>
#include <cstring>

#define $1 CLogger $(__FILE__, __LINE__, __FUNCTION__);         //Use "$1" in first line of function to write in the logfile 

class CLogger
{
	private:
		const char* file_;				//Function file
		const int line_;				//Functoin line
		const char* func_;				//Function name
		
		static FILE* logfile__;                         //File to write
                static int level__;                             //Contains dept of functions call
 	public:	
		CLogger(const char* file, const int line, const char* func):
			file_(file), 
			line_(line),
			func_(func)
		{
			if(logfile__ == NULL)
				logfile__ = fopen("main.cpp.log" , "w");
			level__++;
			for(int i = 1; i < level__; i++)
				fprintf(logfile__ , "  ");
			fprintf(logfile__, "! Func %s in line %d from %s\n", func_, line_, file_);
		}
		
		~CLogger()
		{
			for(int i = 1; i < level__; i++)
                                fprintf(logfile__ , "  ");
			fprintf(logfile__, "? Func %s in line %d from %s\n", func_, line_, file_);
			level__--;
			if(level__ == 0)
				fclose(logfile__);
		}
		//TODO operator <<
};

FILE* CLogger::logfile__;
int   CLogger::level__ = 0;
