// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpConstraintBrokenEvent; size 0x28
#pragma once

struct hkClass;
struct hkpConstraintInstance;
struct hkpConstraintTrackerData;
struct hkpWorld_938ebb10;
struct hkpConstraintBrokenEvent {
    hkpWorld_938ebb10* m_world_0;
    hkpConstraintInstance* m_constraintInstance_8;
    hkClass* m_eventSource_10;
    hkpConstraintTrackerData* m_eventSourceDetails_18;
    float m_actualImpulse_20;
    float m_impulseLimit_24;
};
static_assert(sizeof(hkpConstraintBrokenEvent) == 40, "hkpConstraintBrokenEvent layout differs from the PDB");
