// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"member-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"1254832e5ca7cdca7f6330a2018dde32919625f6149744dd0138e59a943106d8"}
// Code origin: SaveBinary original from the pinned image listing and the community declarations below Stamped as a twin of matched 0xfa0a00 (gamebryo/niparticle/NiPSysModifierCtlr): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTimeController::SaveBinary, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); SaveLinkID is stream slot 0C
// Ownerfb04c0: GUESS(low) STANDIN
// GetCtlrID, member, padding, NiSingleInterpController: GUESS(low) STANDIN
#pragma once
#include "NiPSysModifierCtlr.h"

class Ownerfb04c0 : public NiSingleInterpController
{
public:
    virtual void* GetCtlrID() const;
    void SaveBinary(NiStream& stream) override;
    std::uint8_t padding[0x48];
    void* member;
};

