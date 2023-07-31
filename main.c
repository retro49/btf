#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btf.h"
#include "types.h"

int main(int argc, char** argv)
{
    if(argc < 1){
        DEBUG("error: insufficent argument");
        return 1;
    }
    struct btf_capacity* cap = btf_read_cap();
    if(cap == NULL){
        printf("reading capacity level error\n");
        exit(1);
    }

    printf("%ld\n", cap->bat_percentage);
    btf_free(cap);
}
