// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x95f9a0 MenuControls::Revert
#include "MenuControls_95f9a0.h"

// Re-enables favorites and quick-save handlers and clears beast form state.
void MenuControls::Revert()
{
    if (favoritesHandler)
    {
        favoritesHandler->enabled = true;
    }
    if (quickSaveLoadHandler)
    {
        quickSaveLoadHandler->enabled = true;
    }
    beastForm = false;
}
