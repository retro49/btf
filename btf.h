#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef BTF
#define BTF
#endif

// btf custom types
// unsigned types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long i64;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long u64;

typedef FILE* btf_file;
typedef char* btf_str;

// file path for battery information
#define BAT_PATH "/sys/class/power_supply/BAT0"
#define BAT_CAP BAT_PATH"/""capacity"  // power capacity
#define BAT_CAP_LVL BAT_PATH"/""capacity_level"
#define BAT_CHRG_FULL BAT_PATH"/""charge_full"
#define BAT_CHRG_FULL_DESIGN BAT_PATH"/""charge_full_design"
#define BAT_CHRG_NOW BAT_PATH"/""charge_now"
#define BAT_CURRENT_NOW BAT_PATH"/""current_now"
#define BAT_MANF BAT_PATH"/""manufacturer"
#define BAT_MODEL BAT_PATH"/""model_name"
#define BAT_PRESENT BAT_PATH"/""present"
#define BAT_SERIAL BAT_PATH"/""serial"
#define BAT_STATUS BAT_PATH"/""status"
#define BAT_TECH BAT_PATH"/""technology"
#define BAT_TYPE BAT_PATH"/""type"
#define BAT_VOLT_MIN_DESIGN BAT_PATH"/""voltage_min_design"
#define BAT_VOLT_NOW BAT_PATH"/""voltage_now"
#define BAT_UEVENT BAT_PATH"/""uevent"

#define BAT_AC_PATH "/sys/class/power_supply/AC"
#define BAT_AC_ONLINE BAT_AC_PATH"/""online"
#define BAT_AC_TYPE   BAT_AC_PATH"/""type"
#define BAT_AC_UEVENT BAT_AC_PATH"/""uevent"

#define BTF_ERROR_NOT_FOUND -1
#define BTF_ERROR_ACCESS  -2

#define DEBUG puts

void btf_file_size(const btf_str, u64*);
void btf_reseek_file(btf_file);
u64 btf_read(const btf_str, char*, u64);
bool btf_file_exist(const btf_str);
