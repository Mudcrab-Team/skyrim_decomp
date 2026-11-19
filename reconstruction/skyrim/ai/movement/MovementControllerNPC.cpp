// Source exposure: mixed (local binary analysis and pinned community declarations).
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none.
// 0x796ac0 MovementControllerNPC::Unk_0F
#include "MovementControllerNPC.h"

// ControllerModeWindow: GUESS(low); typed view of the field at target offset 0x1c5.
// MovementControllerNPC::unk1C5: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct ControllerModeWindow {
    std::uint8_t unk1C5;
};

std::uint8_t MovementControllerNPC::Unk_0F() const
{
    const auto& mode = *reinterpret_cast<const ControllerModeWindow*>(reinterpret_cast<const char*>(this) + 0x1c5);  // 0x1c5 unk1C5
    return mode.unk1C5;
}
