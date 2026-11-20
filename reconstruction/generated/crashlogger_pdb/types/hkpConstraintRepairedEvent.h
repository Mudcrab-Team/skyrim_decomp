// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintRepairedEvent; size 0x20
#pragma once

struct hkClass;
struct hkpConstraintInstance;
struct hkpConstraintTrackerData;
struct hkpWorld_938ebb10;
struct hkpConstraintRepairedEvent {
    hkpWorld_938ebb10* m_world_0;
    hkpConstraintInstance* m_constraintInstance_8;
    hkClass* m_eventSource_10;
    hkpConstraintTrackerData* m_eventSourceDetails_18;
};
static_assert(sizeof(hkpConstraintRepairedEvent) == 32, "hkpConstraintRepairedEvent layout differs from the PDB");
