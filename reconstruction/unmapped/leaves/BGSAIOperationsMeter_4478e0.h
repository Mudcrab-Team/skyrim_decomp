// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIOpsMeter.cpp:137
// BGSAIOperationsMeter, BGSAIOperationsMeter::CheckPermissionForPathing: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// PlayerCharacter::IsSleepingorResting: SIBLING(fo4-private@1b765c70, author-permission)
// BGSAIOperationsMeter::pathRequestsAllowedThisFrame, BGSAIOperationsMeter::pathRequestsAllowedPerFrame, BGSAIOperationsMeter::pathRequestsDeniedThisFrame, BGSAIOperationsMeter::pathRequestsDeniedTotal, PlayerCharacter::singleton: GUESS(low)
#pragma once

#include <cstdint>

class PlayerCharacter
{
public:
    bool IsSleepingorResting() const;

    static PlayerCharacter* singleton;
};

class BGSAIOperationsMeter
{
public:
    bool CheckPermissionForPathing();

    std::uint32_t unknown00;                       // 00
    std::uint32_t pathRequestsAllowedThisFrame;    // 04
    std::uint32_t pathRequestsAllowedPerFrame;     // 08
    std::uint32_t pathRequestsDeniedThisFrame;     // 0C
    std::uint32_t unknown10;                       // 10
    std::uint32_t pathRequestsDeniedTotal;         // 14
};
