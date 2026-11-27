// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x95f920 MenuControls::LoadGame
#include "MenuControls_95f920.h"

// Loads handler enable flags and optional beast form flag from the save buffer.
void MenuControls::LoadGame(BGSLoadFormBuffer* a_buf)
{
    bool enabled;
    a_buf->Read(&enabled, 1, 1);
    if (favoritesHandler)
    {
        favoritesHandler->enabled = enabled;
    }
    if (quickSaveLoadHandler)
    {
        quickSaveLoadHandler->enabled = enabled;
    }
    if (a_buf->GetVersion() >= 0x2A)
    {
        a_buf->Read(&beastForm, 1, 1);
    }
}
