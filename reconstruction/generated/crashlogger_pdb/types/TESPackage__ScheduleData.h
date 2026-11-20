// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackage__ScheduleData; size 0xc
#pragma once
struct TESPackage__ScheduleData {
    char Month_0;
    char DayOfWeek_1;
    char Date_2;
    char Hour_3;
    char Minute_4;
    char _pad_5[3];
    int DurationMinutes_8;
};
static_assert(sizeof(TESPackage__ScheduleData) == 12, "TESPackage__ScheduleData layout differs from the PDB");
