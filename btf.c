#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "btf.h"

// returns the total size of a file in bytes
void btf_file_size(const btf_str f, u64* res)
{
    if(f == NULL){
        *res = BTF_ERROR_NOT_FOUND;
        return;
    }
    struct stat s;
    i32 stat_ret = lstat(f, &s);
    if(stat_ret == -1){
        *res = BTF_ERROR_ACCESS;
        return;
    }
    *res = s.st_size;
}

bool btf_file_exist(const btf_str path)
{
    struct stat fs;
    return lstat(path, &fs) != -1;
}

u64 btf_read(const btf_str source, char* buff, u64 size)
{
    i32 fd = open(source, O_RDONLY);
    if(fd == -1){
        return -1;
    }
    u64 red = read(fd, buff, size);
    close(fd);
    return red;
}
