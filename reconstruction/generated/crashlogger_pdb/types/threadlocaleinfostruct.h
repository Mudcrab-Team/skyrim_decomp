// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: threadlocaleinfostruct; size 0x158
#pragma once

#include "localerefcount.h"
struct lc_time_data;
struct lconv;
struct threadlocaleinfostruct {
    int refcount;
    unsigned int lc_codepage;
    unsigned int lc_collate_cp;
    unsigned int lc_time_cp;
    localerefcount lc_category[6];
    int lc_clike;
    int mb_cur_max;
    int* lconv_intl_refcount;
    int* lconv_num_refcount;
    int* lconv_mon_refcount;
    struct lconv* lconv;
    int* ctype1_refcount;
    unsigned short* ctype1;
    unsigned short* pctype;
    unsigned char* pclmap;
    unsigned char* pcumap;
    lc_time_data* lc_time_curr;
    wchar_t* locale_name[6];
};
static_assert(sizeof(threadlocaleinfostruct) == 344, "threadlocaleinfostruct layout differs from the PDB");
