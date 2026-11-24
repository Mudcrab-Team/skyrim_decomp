// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorFlankingMovement.cpp:149
// CombatFlankingSearchData, LoadGame, StartLocation, GoalLocation, StartDirection, ChosenLocation, fStartAngle, fGoalAngle: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// fCurrentAngle, fStartDistance, fFlankDistance, fRange, uiDirection, BGSLoadGameBuffer, LoadDataEndian, CombatObject: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// CombatFlankingSearchData: CRASHLOGGER_PDB(59818@2026.10.24)
// Point3, unk04: GUESS(low)
#pragma once

#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_dest, std::uint32_t a_size, std::uint32_t a_width);
};

struct Point3
{
    float x;
    float y;
    float z;
};

class CombatObject
{
public:
    virtual ~CombatObject();
    virtual void DeleteThis();

    std::uint32_t m_uiRefCount;
};

class CombatFlankingSearchData : public CombatObject
{
public:
    virtual void LoadGame(BGSLoadGameBuffer* a_buffer);  // compared: 0x899c20

    Point3 StartLocation;     // 10
    Point3 GoalLocation;      // 1C
    Point3 StartDirection;    // 28
    Point3 ChosenLocation;    // 34
    float fStartAngle;        // 40
    float fGoalAngle;         // 44
    float fCurrentAngle;      // 48
    float fStartDistance;     // 4C
    float fFlankDistance;     // 50
    float fRange;             // 54
    std::uint32_t uiDirection;  // 58
};
