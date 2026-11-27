// Exposure detail: (community declarations; local target observations).
// Source exposure: mixed
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysRotationModifier, NiPSysRotationModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier, NiPSysModifier::IsEqual, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_fInitialRotSpeed, m_fInitialRotSpeedVar, m_fInitialRotAngle, m_fInitialRotAngleVar, m_kInitialAxis, m_bRandomInitialAxis, m_bRandomRotSpeedSign: SYMBOLS(fo4-pdb)
// baseStorage: GUESS(low); unmodelled base state

#pragma once
#include <cstdint>
class NiObject;
class NiPSysModifier
{
public:
    bool IsEqual(NiObject* object);
    std::uint8_t baseStorage[0x30];
};
class NiPSysRotationModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object);
    float m_fInitialRotSpeed;
    float m_fInitialRotSpeedVar;
    float m_fInitialRotAngle;
    float m_fInitialRotAngleVar;
    float m_kInitialAxis[3];
    bool m_bRandomInitialAxis;
    bool m_bRandomRotSpeedSign;
};
static_assert(sizeof(NiPSysRotationModifier) == 0x50, "rotation modifier layout");
