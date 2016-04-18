#pragma once

#include <stdio.h>
#include <cstring>

#define $1 CLogger $(__FILE__, __LINE__, __FUNCTION__);         //Use "$1" in first line of function to write in the logfile 
								//Use "$<<"<your string>"" in any file to write <your strung> into log
#define  logfileASSERT\
		if(logfile__ == NULL)\
                {\
                	printf("Can't open logfile <main.cpp.log>");\
                        exit(0);\
                }

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
			///open logfile, if it doesn't
			if(logfile__ == NULL)
				logfile__ = fopen("main.cpp.log" , "w");

			///FIXME logfile_assert	
			logfileASSERT;			
	
			if(logfile__ == NULL)
			{
				printf("Can't open logfile <main.cpp.log>");
				exit(0);
			}
			
			level__++;
			for(int i = 1; i < level__; i++)
				fprintf(logfile__ , "  ");
			fprintf(logfile__, "! Func %s in line %d from %s\n", func_, line_, file_);	
			fflush(logfile__);
		}
		
		~CLogger()
		{
			logfileASSERT;
			for(int i = 1; i < level__; i++)
                                fprintf(logfile__ , "  ");
			fprintf(logfile__, "? Func %s in line %d from %s\n", func_, line_, file_);	
			fflush(logfile__);		
			level__--;
			if(level__ == 0)
				fclose(logfile__);
		}
		void operator<<(const char* s)
		{
			logfileASSERT;
			for(int i = 0; i < level__; i++)
				fprintf(logfile__, "  ");
			fprintf(logfile__, "%s\n", s);
		}
};

FILE* CLogger::logfile__;
int   CLogger::level__ = 0;

#undef logfileASSERT
