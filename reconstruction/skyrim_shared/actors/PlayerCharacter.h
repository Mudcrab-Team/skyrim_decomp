// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"low","kind":"guess","owner":"PlayerCharacter","rationale":"vtable owner and slot; method spelling invented","slot":8},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Slot8 was synthesized from the bounded leaf template.
// PlayerCharacter: EXE_RTTI
// Slot8: GUESS(low)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// Slot8: GUESS(low); method name inferred from vtable owner and slot
// MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class MovementControllerNPC;
class PlayerCharacter
{
public:
    virtual std::uint8_t Slot8() const;
    // SetAIDriven: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // GetMovementController: GUESS(low)
    void SetAIDriven(bool a_driven);
    MovementControllerNPC* const& GetMovementController();
};
