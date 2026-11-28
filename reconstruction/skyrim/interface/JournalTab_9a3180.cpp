// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x9a3180 JournalTab::dtor
#include "JournalTab_9a3180.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
JournalTab::JournalTab()
{
}

// Notify the associated journal view when this tab is destroyed.
JournalTab::~JournalTab()
{
    if (view != nullptr) {
        view->OnTabDestroyed();
    }
}
