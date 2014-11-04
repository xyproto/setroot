#include <stdlib.h>
#include <errno.h>

#define MEMORY_ERROR "Not enough memory for allocation."
#define HEXTOINT(dd) (int) strtol(dd, NULL, 16)

void die( unsigned int error_code, char* error_msg )
{
	fprintf(stderr, "Error in %s at line %d: %s\n", __FILE__, __LINE__, error_msg );
	exit(error_code);
}

void clean( void *ptr )
{
	if (ptr != NULL) { free(ptr); ptr = NULL; }
}

void verify( void *ptr )
{
	if (ptr == NULL) { die( 1, MEMORY_ERROR ); }
}
