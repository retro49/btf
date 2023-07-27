#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btf.h"

int main(int argc, char** argv)
{
    if(argc < 2){
        DEBUG("error: insufficent argument");
        return 1;
    }
    // a test reading
    char buff[16];
    btf_read("./btf.h", buff, 16);
    DEBUG(buff);
    printf("%ld\n", strlen(buff));
    printf("%d\n", *(buff+15));
    printf("%d\n", *(buff+16));
    printf("%d\n", *(buff+17));
}
