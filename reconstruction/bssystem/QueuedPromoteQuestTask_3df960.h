// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// QueuedPromoteQuestTask, QueuedPromoteQuestTask::sub_140380420: CRASHLOGGER_PDB(59818@2026.10.24)
// TESQuest3df960, GetName, formID, FormatTaskDesc, gPromoteQuestFormat, quest: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESQuest3df960
{
public:
    virtual ~TESQuest3df960();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17(); virtual void Unk_18();
    virtual void Unk_19(); virtual void Unk_1A(); virtual void Unk_1B(); virtual void Unk_1C();
    virtual void Unk_1D(); virtual void Unk_1E(); virtual void Unk_1F(); virtual void Unk_20();
    virtual void Unk_21(); virtual void Unk_22(); virtual void Unk_23(); virtual void Unk_24();
    virtual void Unk_25(); virtual void Unk_26(); virtual void Unk_27(); virtual void Unk_28();
    virtual void Unk_29(); virtual void Unk_2A(); virtual void Unk_2B(); virtual void Unk_2C();
    virtual void Unk_2D(); virtual void Unk_2E(); virtual void Unk_2F(); virtual void Unk_30();
    virtual void Unk_31();
    virtual const char* GetName();  // 0x32 (0x190)

    std::uint8_t  unk08[0x0C];  // 08
    std::uint32_t formID;       // 14
};
static_assert(offsetof(TESQuest3df960, formID) == 0x14, "formID offset");

int FormatTaskDesc(char* a_buf, std::size_t a_size, const char* a_fmt, ...);
extern const char gPromoteQuestFormat[];

class QueuedPromoteQuestTask
{
public:
    bool sub_140380420(char* a_buf, std::uint32_t a_size);  // compared: 0x3df960

    std::uint8_t    unk00[0x50];  // 00
    TESQuest3df960* quest;        // 50
};
static_assert(offsetof(QueuedPromoteQuestTask, quest) == 0x50, "quest offset");
