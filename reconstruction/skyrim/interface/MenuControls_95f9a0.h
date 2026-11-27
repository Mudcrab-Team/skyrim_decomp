// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// MenuControls, MenuControls::Revert, MenuControls::quickSaveLoadHandler, MenuControls::favoritesHandler, MenuControls::beastForm, QuickSaveLoadHandler, FavoritesHandler: CRASHLOGGER_PDB(59818@2026.10.24)
// FavoritesHandler::enabled, QuickSaveLoadHandler::enabled: GUESS
#pragma once

#include <cstdint>

struct QuickSaveLoadHandler
{
    std::uint8_t unk00[0x10];
    bool enabled;
};

struct FavoritesHandler
{
    std::uint8_t unk00[0x0C];
    bool enabled;
};

class MenuControls
{
  public:
    void Revert();

    std::uint8_t unk00[0x68];
    QuickSaveLoadHandler* quickSaveLoadHandler;
    FavoritesHandler* favoritesHandler;
    void* screenshotHandler;
    bool isProcessing;
    bool beastForm;
};
