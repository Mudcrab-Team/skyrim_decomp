// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); placeholder class, a view of the process member only
// Character::IsWieldingMeleeOrUnarmed: GUESS(low)
// Character::pad00, TESForm::pad00, TESObjectWEAP::unread1B: GUESS(low); unread bytes before the members used
// currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's member at 0xF0, 8 bytes later in this build
// AIProcess, TESForm, TESObjectWEAP: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the body reads
// GetEquippedLeftHand, GetEquippedRightHand, formType, FormType, Weapon, animationType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the right-hand getter's address is a guess from its neighbour, and NG types animationType as an unsigned enumeration byte where the target reads it signed
#pragma once

#include <cstdint>
#include <cstddef>

enum class FormType : std::uint8_t
{
    Weapon = 0x29
};

class TESForm
{
public:
    std::uint8_t pad00[0x1A];
    FormType     formType;  // 1A
};

class TESObjectWEAP : public TESForm
{
public:
    std::uint8_t unread1B[0x19D - 0x1B];
    std::int8_t  animationType;  // 19D, weaponData (168) + 35
};

class AIProcess
{
public:
    TESForm* GetEquippedLeftHand();
    TESForm* GetEquippedRightHand();
};

class Character
{
public:
    bool IsWieldingMeleeOrUnarmed();  // compared: 0x868df0

    std::uint8_t pad00[0xF8];
    AIProcess*   currentProcess;  // F8
};
