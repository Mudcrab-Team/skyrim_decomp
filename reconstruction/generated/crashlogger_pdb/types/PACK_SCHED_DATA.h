// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PACK_SCHED_DATA; size 0xc
#pragma once
struct PACK_SCHED_DATA {
    unsigned char month;
    unsigned char dayOfWeek;  // DayOfWeek in the PDB is wider than this slot
    unsigned char date;
    unsigned char hour;
    unsigned char minute;
    unsigned char pad5;
    unsigned char pad6;
    unsigned char pad7;
    int duration;
};
static_assert(sizeof(PACK_SCHED_DATA) == 12, "PACK_SCHED_DATA layout differs from the PDB");
