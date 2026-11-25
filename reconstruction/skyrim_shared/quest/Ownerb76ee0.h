// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of Function3ab500. Stamped as a twin of matched 0x3ab280 (skyrim_shared/quest/BGSSceneActionDialogue): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// EmotionType: GUESS(low)
// Ownerb76ee0: GUESS(low) STANDIN
// GetType, GetEmotionType, GetEmotionValue, Loops, FacesTarget, Unk_0B, BGSSceneActionBase, Function3ab500: GUESS(low) STANDIN
#pragma once
#include "BGSSceneActionDialogue.h"

class Ownerb76ee0 : public BGSSceneActionBase
{
public:
    Ownerb76ee0();
    enum class Type : std::uint32_t {};
    virtual Type GetType() const;
    virtual EmotionType GetEmotionType() const;
    virtual std::uint32_t GetEmotionValue() const;
    virtual bool Loops() const;
    virtual bool FacesTarget() const;
    virtual void Unk_0B();
    virtual ~Ownerb76ee0() {}
    void Function3ab500();
};
static_assert(sizeof(Ownerb76ee0) == 0x40, "Ownerb76ee0 size");
