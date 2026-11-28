// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1e3540 Unit1e3540::GetFormTypeName1e3540
// Adapted bodies: none
#include "Unit1e3540.h"

#include <cstring>

// Looks up the factory for a form's type byte and returns its name, or a default fallback string.
const char* Unit1e3540::GetFormTypeName1e3540(const Form1e3540* a_form)
{
    std::uint8_t type = a_form->formType;
    if (!g_tableInitialized1e3540) {
        std::memset(g_factoryTable1e3540, 0, sizeof(g_factoryTable1e3540));
        g_tableInitialized1e3540 = true;
    }
    if (type < kTableCount && g_factoryTable1e3540[type]) {
        return g_factoryTable1e3540[type]->GetName();
    }
    return g_defaultName1e3540;
}
