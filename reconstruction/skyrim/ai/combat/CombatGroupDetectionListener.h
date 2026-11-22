// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: original; the listing and community declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DetectionListener: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// CombatGroupDetectionListener, CombatGroupDetectionListener::Unk_02, CombatGroupDetectionListener::~CombatGroupDetectionListener, CombatGroupDetectionListener::Unk_05: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class DetectionListener
{
public:
    virtual ~DetectionListener();

    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(DetectionListener) == 0x10, "DetectionListener size");

class CombatGroupDetectionListener : public DetectionListener
{
public:
    ~CombatGroupDetectionListener() override;  // 00
    virtual void Unk_02();  // compared: 0xeebf20  // slot 01
    virtual void Unk_05(void);  // 01

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint8_t unknown10[0x8];  // 10
};
static_assert(sizeof(CombatGroupDetectionListener) == 0x18, "CombatGroupDetectionListener size");
