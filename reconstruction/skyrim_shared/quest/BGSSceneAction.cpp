// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x3ab090 BGSSceneAction::Unk_0B
// 0x3ab120 BGSSceneAction::Unk_10
// 0x3aaf60 BGSSceneAction::ClearFlags
// 0x3ab130 BGSSceneAction::Unk_11
// 0x3aaf20 BGSSceneAction::Unk_02
#include <atomic>

#include "BGSSceneAction.h"

// TODO body: RVA 0x3ab090, 5 bytes, BGSSceneAction::Unk_0B.
void BGSSceneAction::Unk_0B()
{
    flags14 &= 0xfc;
}

// TODO body: RVA 0x3ab120, 5 bytes, BGSSceneAction::Unk_10.
void BGSSceneAction::Unk_10()
{
    flags14 |= 1;
}

// TODO body: RVA 0x3aaf60, 8 bytes, BGSSceneAction::ClearFlags.
void BGSSceneAction::ClearFlags()
{
    flags10 = 0;
}

// TODO body: RVA 0x3ab130, 33 bytes, BGSSceneAction::Unk_11.
void BGSSceneAction::Unk_11()
{
    flags14 &= 0xfe;
    if (!Unk_05()) {
        flags14 |= 2;
    }
}

// TODO body: RVA 0x3aaf20, 58 bytes, BGSSceneAction::Unk_02.
void BGSSceneAction::Unk_02(BGSSceneAction* a_other)
{
    const auto flags = unknown08;
    unknown08 = FindSceneActionEntry(a_other->unknown98, flags) ? flags : 0xffffffff;
    std::atomic_signal_fence(std::memory_order_seq_cst);
}

bool BGSSceneAction::Unk_05()
{
    return false;
}
