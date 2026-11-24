// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// StandIn_00a537a0: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// StandIn_00a537a0::Func00a537a0: GUESS(low); placeholder name
// padding_0_, padding_14_: GUESS(low); placeholder name
#pragma once

void UpdateSlotStates(unsigned int, unsigned int, void*&, unsigned int&, float, float);
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct StandIn_00a537a0
{
  public:
    char padding_0_[16];
    unsigned int m_uiNumKeys;
    char padding_14_[4];
    void *m_pKeyArray;
    unsigned int m_eRequestType;
    void Func00a537a0(float m_fStartTime, float m_fMaximumDistance);
};
