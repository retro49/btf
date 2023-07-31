#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "btf.h"
#include "types.h"
#include "util.h"

// capacity

struct btf_capacity* btf_read_cap()
{
    if(!btf_file_exist(BAT_CAP))
        return NULL;

    u64 fsize;
    btf_file_size(BAT_CAP, &fsize);
    if(fsize == 0)
        return NULL;

    btf_str content = btf_alloc(sizeof(char) * fsize);
    if(content == NULL)
        return NULL;

    btf_read(BAT_CAP, content, fsize);
    struct btf_capacity* cap = 
        (struct btf_capacity*)btf_alloc(sizeof(struct btf_capacity));
    cap->bat_percentage = atoi(content);
    // gotcha free
    btf_free(content);
    return cap;
}
