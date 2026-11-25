// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: original compact layout using target observations
// SPDX-License-Identifier: CC0-1.0
// TESAIForm, TESAIForm::AIData: SIBLING(fo4-private@1b765c70, author-permission)
// TESAIForm::Function1de8f0: GUESS(low); neutral RVA name
// TESAIForm::vptr: GUESS(low) STANDIN; unaccessed base component storage
#pragma once
#include <cstddef>
#include <cstdint>
class TESAIForm {
public:
    void Function1de8f0(TESAIForm* source);
    void* vptr;
    uint8_t AIData[12];
};
static_assert(offsetof(TESAIForm, AIData) == 8, "AI data offset");
