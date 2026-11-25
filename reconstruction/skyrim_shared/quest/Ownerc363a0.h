// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of Function3ab500. Stamped as a twin of matched 0x3ab280 (skyrim_shared/quest/BGSSceneActionDialogue): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EmotionType: GUESS(low)
// Ownerc363a0: GUESS(low) STANDIN
// GetType, GetEmotionType, GetEmotionValue, Loops, FacesTarget, Unk_0B, BGSSceneActionBase, Function3ab500: GUESS(low) STANDIN
#pragma once
#include "BGSSceneActionDialogue.h"

class Ownerc363a0 : public BGSSceneActionBase
{
public:
    Ownerc363a0();
    enum class Type : std::uint32_t {};
    virtual Type GetType() const;
    virtual EmotionType GetEmotionType() const;
    virtual std::uint32_t GetEmotionValue() const;
    virtual bool Loops() const;
    virtual bool FacesTarget() const;
    virtual void Unk_0B();
    virtual ~Ownerc363a0() {}
    void Function3ab500();
};
static_assert(sizeof(Ownerc363a0) == 0x40, "Ownerc363a0 size");
