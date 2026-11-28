// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSAnimNoteReceiver, AnimNoteReceiverBase221470: CRASHLOGGER_PDB(59818@2026.10.24)
// AnimNoteEntry221470, AnimNoteArray221470, NiFree221470, notes: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

extern void NiFree221470(void* a_ptr);

struct AnimNoteEntry221470
{
    std::uint64_t unk00;
    std::uint64_t unk08;
};

class AnimNoteArray221470
{
public:
    virtual ~AnimNoteArray221470()
    {
        NiFree221470(data);
    }

    AnimNoteEntry221470* RemoveEnd()
    {
        if (size == 0)
        {
            return nullptr;
        }
        --size;
        AnimNoteEntry221470* item = data[size];
        data[size] = nullptr;
        if (item != nullptr)
        {
            --esize;
        }
        return item;
    }

    AnimNoteEntry221470** data;
    std::uint16_t maxSize;
    std::uint16_t size;
    std::uint16_t esize;
    std::uint16_t growBy;
};

class AnimNoteReceiverBase221470
{
public:
    virtual ~AnimNoteReceiverBase221470() {}

    std::uint64_t unk08;
};

class BSAnimNoteReceiver : public AnimNoteReceiverBase221470
{
public:
    BSAnimNoteReceiver();
    ~BSAnimNoteReceiver() override;

    AnimNoteArray221470 notes;
};

static_assert(sizeof(AnimNoteEntry221470) == 0x10, "AnimNoteEntry221470 size");
static_assert(offsetof(BSAnimNoteReceiver, notes) == 0x10, "notes offset");
static_assert(sizeof(BSAnimNoteReceiver) == 0x28, "BSAnimNoteReceiver size");
