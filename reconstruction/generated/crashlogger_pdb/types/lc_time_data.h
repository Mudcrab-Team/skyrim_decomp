// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: __lc_time_data; size 0x2c0
#pragma once
struct lc_time_data {
    char* wday_abbr[7];
    char* wday[7];
    char* month_abbr[12];
    char* month[12];
    char* ampm[2];
    char* ww_sdatefmt;
    char* ww_ldatefmt;
    char* ww_timefmt;
    int ww_caltype;
    int refcount;
    wchar_t* _W_wday_abbr[7];
    wchar_t* _W_wday[7];
    wchar_t* _W_month_abbr[12];
    wchar_t* _W_month[12];
    wchar_t* _W_ampm[2];
    wchar_t* _W_ww_sdatefmt;
    wchar_t* _W_ww_ldatefmt;
    wchar_t* _W_ww_timefmt;
    wchar_t* _W_ww_locale_name;
};
static_assert(sizeof(lc_time_data) == 704, "lc_time_data layout differs from the PDB");
