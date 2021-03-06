#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main( int argc, char *argv[] ){
	// Create time structs
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	// Check if file extension passed
	char extension[4];
	if(argc > 1){
		if(0 == strcmp(argv[1], "-h")){
			printf("usage: %s [options] [file extension]\n  options:\n    -h Print this help message\n", argv[0]);
			return 0;
		}
		else{
			strcpy(extension, argv[1]);
		}
	}
	else{
		strcpy(extension, "md");
	}

	// Define filename
	char filename[15];
	sprintf(filename, "%d-%02d-%02d.%s",tm.tm_year + 1900,tm.tm_mon+1,tm.tm_mday,extension);

	// Check if file already exists
	struct stat sb;
	int fileDoesntExist = stat(filename,&sb);

	if(fileDoesntExist){
		// Create file
		FILE *fp = fopen(filename,"a+");
		fclose( fp );
		printf("%s\n",filename);
		return 0;
	}
	else{
		printf("File already exists\n");
		return 1;
	}
}