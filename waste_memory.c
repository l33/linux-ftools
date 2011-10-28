#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h> 

/*
 */
int main(int argc, char *argv[]) {

    int res;

    //number of bytes we should attempt to allocate.
    unsigned int len = 1 * 1024 * 1024 * 1024;

    if ( argc == 1 ) 
        len = atoi( argv[0] );

    printf( "Allocating %i bytes ...", len );

    void *buff = malloc( len );

    if ( buff == NULL ) {
       printf( "\nFailed to malloc." );
       exit( EXIT_FAILURE );
    }

    memset( buff, 1, len );

    printf( "done\n" );

    fflush( stdout );

    sleep( 2147483648 );

}
