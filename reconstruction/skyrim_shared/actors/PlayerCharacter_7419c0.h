// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter, PlayerCharacter::SetHighFlag7419c0, flagByte, flag: GUESS(low)
#pragma once

struct FlagByte
{
    unsigned char low : 7;
    unsigned char flag : 1;
};

class PlayerCharacter
{
public:
    void SetHighFlag7419c0(bool value);

    char unk00[0xBEA];
    FlagByte flagByte;
};
