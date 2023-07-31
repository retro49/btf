#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "types.h"

#ifndef BTF
#define BTF

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

// its just an integer okay
struct btf_capacity {
    i64 bat_percentage;
};

// guess what, somehow you have to clean this memory
// well every string must be cleaned from the heap
struct btf_capapcity_level {
    btf_str bat_level;
};

// well, we dont have an 8KB ram so long isnt bad.
struct btf_charge_full{
    i64 bat_chrg_full;
};

struct btf_charge_full_design{
    i64 bat_charge_full_design;
};

struct btf_charge_now {
    i64 bat_chrg_now;
};

struct btf_current_now {
    i64 bat_current_now;
};

// still its a string and plz plz clean it up
// after you finished dude... this is my comment
struct btf_manufacturer {
    btf_str bat_manf;
};

// here we go, clean up kay!
struct btf_model{
    btf_str bat_model;
};

struct btf_present {
    i64 bat_present;
};

// the string is here too.
struct btf_serial {
    btf_str bat_serial;
};

// yep clean it again.
struct btf_status {
    btf_str bat_status;
};

// okay okaaay okaaaaay, clean it up.
struct btf_tech {
    btf_str bat_tech;
};

struct btf_type {
    btf_str bat_type;
};

struct btf_volt_min_design {
    i64 bat_volt_min_dis;
};

struct btf_volt_now {
    i64 bat_volt_now;
};

// uevent, where they all gather. yep.
struct btf_uevent {
    struct btf_capacity charge_capacity;
    struct btf_charge_full charge_full;
    struct btf_charge_full_design charge_full_design;
    struct btf_charge_now charge_now;
    struct btf_current_now current_now;
    struct btf_manufacturer manufacturer;
    struct btf_model model;
    struct btf_present present;
    struct btf_serial serial;
    struct btf_status status;
    struct btf_tech technology;
    struct btf_type type;
    struct btf_volt_min_design volt_min_design;
    struct btf_volt_now volt_now;
};


// prototype for testing memory
struct btf_capacity* btf_read_cap();

#endif
