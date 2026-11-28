// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// BSSystemUtility, SetLostFocus: CRASHLOGGER_PDB(59818@2026.10.24)
// FocusCallback, onFocusChanged, lostFocus, unk00, unk100, unk11D: GUESS(low)
#pragma once

#include <cstdint>

class BSSystemUtility
{
public:
    using FocusCallback = void (*)(bool);

    void SetLostFocus(bool value);

    std::uint8_t  unk00[0xF8];     // 000
    FocusCallback onFocusChanged;  // 0F8
    std::uint8_t  unk100[0x1C];    // 100
    bool          lostFocus;       // 11C
    std::uint8_t  unk11D[0xB];     // 11D
};
static_assert(sizeof(BSSystemUtility) == 0x128, "BSSystemUtility size");
