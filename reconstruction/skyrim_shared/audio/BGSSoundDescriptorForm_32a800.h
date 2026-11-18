// BGSSoundDescriptorForm, BSISoundDescriptor, BGSSoundDescriptor, soundDescriptor, Func2, Unk1: GUESS(low)
// Inferred names: GUESS(low)
// Origin: reconstruction informed by CommonLibSSE-NG public declarations, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
// BGSSoundDescriptorForm, BSISoundDescriptor, BGSSoundDescriptor, soundDescriptor, Func2, Unk1: GUESS(low)
class BSISoundDescriptor {
public:
    virtual ~BSISoundDescriptor();
    virtual void Unk1();
    virtual bool Func2();
};
class BGSSoundDescriptor : public BSISoundDescriptor {};
class BGSSoundDescriptorForm : public BSISoundDescriptor {
public:
    bool Func2() override;
    BGSSoundDescriptor* soundDescriptor;
};
