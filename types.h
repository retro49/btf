#include <stdio.h>
#include <stdlib.h>

// signed types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;


// unsigned types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef FILE* btf_file;
typedef char* btf_str;

#define btf_alloc malloc
#define btf_free free
