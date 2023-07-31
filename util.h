#include "btf.h"
#include "types.h"
#include <fcntl.h>

void btf_file_size(const btf_str, u64*);
void btf_reseek_file(btf_file);
u64 btf_read(const btf_str, char*, u64);
bool btf_file_exist(const btf_str);

