// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: member names and the stream interface adapted from the sibling; offsets and slots read from the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementPlannerAgentWarp.cpp:110
// MovementPlannerAgentWarp, MovementPlannerAgentWarp::SaveGame: EXE_RTTI SIBLING(fo4-private@1b765c70, author-permission)
// MovementPlannerAgentWarp::LastFailureLocation, WarpLocation, fWarpTimer, pActor, eState, uiPathFailureCount, BSPathingLocation, BSPathingLocation::Write, BSPathingStreamWrite, BSPathingStreamWrite::DoWrite, BSPathingStreamWrite::DoWriteNumericID: SIBLING(fo4-private@1b765c70, author-permission)
// Actor, Actor::iFormID: STANDIN SIBLING(fo4-private@1b765c70, author-permission); only the form id member is modelled
// BSPathingStreamWrite::DoWrite(unsigned short), BSPathingStreamWrite::DoWrite(unsigned char), BSPathingStreamWrite::unk05, unk06, unk07, unk08, unk09, unk10: GUESS(low); slot placeholders
#pragma once

class BSPathingStreamWrite
{
public:
    virtual ~BSPathingStreamWrite();                   // 00
    virtual void DoWrite(unsigned int a_value);        // 04, the overload group is laid out in reverse declaration order
    virtual void DoWrite(unsigned short a_value);      // 03
    virtual void DoWrite(unsigned char a_value);       // 02
    virtual void DoWrite(float a_value);               // 01
    virtual void unk05();                              // 05
    virtual void unk06();                              // 06
    virtual void unk07();                              // 07
    virtual void unk08();                              // 08
    virtual void unk09();                              // 09
    virtual void unk10();                              // 0A
    virtual void DoWriteNumericID(unsigned int a_id);  // 0B
};

class BSPathingLocation
{
public:
    void Write(BSPathingStreamWrite& a_stream) const;  // bound: 0x11b8320

    unsigned char unk00[0x30];  // 00
};

class Actor
{
public:
    unsigned char unk00[0x14];  // 00
    unsigned int iFormID;       // 14
};

class MovementPlannerAgentWarp
{
public:
    virtual void SaveGame(BSPathingStreamWrite& a_stream) const;  // compared: 0x7a9dd0

    unsigned char unk08[0x20];          // 08
    BSPathingLocation LastFailureLocation;  // 28
    BSPathingLocation WarpLocation;         // 58
    float fWarpTimer;                       // 88
    Actor* pActor;                          // 90
    unsigned char unk98[0x18];          // 98
    unsigned int eState;                    // B0
    unsigned int uiPathFailureCount;        // B4
};
