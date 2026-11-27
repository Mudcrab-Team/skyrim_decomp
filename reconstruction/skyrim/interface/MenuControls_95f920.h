// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// MenuControls, MenuControls::LoadGame, MenuControls::quickSaveLoadHandler, MenuControls::favoritesHandler, MenuControls::beastForm, QuickSaveLoadHandler, FavoritesHandler: CRASHLOGGER_PDB(59818@2026.10.24)
// FavoritesHandler::enabled, QuickSaveLoadHandler::enabled, BGSLoadFormBuffer, BGSLoadFormBuffer::GetVersion, BGSLoadFormBuffer::Read: GUESS
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

class BGSLoadFormBuffer
{
  public:
    virtual ~BGSLoadFormBuffer();
    virtual std::uint8_t GetVersion();

    void Read(void* a_dest, std::uint32_t a_size, std::uint32_t a_count);
};

class MenuControls
{
  public:
    void LoadGame(BGSLoadFormBuffer* a_buf);

    std::uint8_t unk00[0x68];
    QuickSaveLoadHandler* quickSaveLoadHandler;
    FavoritesHandler* favoritesHandler;
    void* screenshotHandler;
    bool isProcessing;
    bool beastForm;
};
