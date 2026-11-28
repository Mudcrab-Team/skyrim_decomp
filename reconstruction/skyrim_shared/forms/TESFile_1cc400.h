// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESFile, TESFile::masters, TESFile::mastersData, WIN32_FIND_DATAA: CRASHLOGGER_PDB(59818@2026.10.24)
// TESFile::HasInvalidMasterFile, TESFile::unk000, MasterFileSize, MasterFileSize::low, MasterFileSize::high, SimpleListNode, SimpleListNode::item, SimpleListNode::next, FormatPath, FindFirstFileA, FindClose, kMasterFilePathFormat, WIN32_FIND_DATAA::unk00, WIN32_FIND_DATAA::nFileSizeHigh, WIN32_FIND_DATAA::nFileSizeLow, WIN32_FIND_DATAA::unk24: GUESS(low); offsets and calls observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

struct WIN32_FIND_DATAA
{
    std::uint8_t  unk00[0x1C];    // 00
    std::uint32_t nFileSizeHigh;  // 1C
    std::uint32_t nFileSizeLow;   // 20
    std::uint8_t  unk24[0x11C];   // 24
};
static_assert(sizeof(WIN32_FIND_DATAA) == 0x140, "WIN32_FIND_DATAA size");
static_assert(offsetof(WIN32_FIND_DATAA, nFileSizeHigh) == 0x1C, "nFileSizeHigh offset");
static_assert(offsetof(WIN32_FIND_DATAA, nFileSizeLow) == 0x20, "nFileSizeLow offset");

extern "C" {
__declspec(dllimport) void* __stdcall FindFirstFileA(const char* a_fileName, WIN32_FIND_DATAA* a_findFileData);
__declspec(dllimport) std::int32_t __stdcall FindClose(void* a_findFile);
}

extern const char kMasterFilePathFormat[];

std::int32_t FormatPath(char* a_buffer, std::size_t a_size, const char* a_format, ...);

struct MasterFileSize
{
    std::uint32_t low;   // 00
    std::uint32_t high;  // 04
};

template <class T>
struct SimpleListNode
{
    T               item;  // 00
    SimpleListNode* next;  // 08
};

class TESFile
{
public:
    bool HasInvalidMasterFile() const;

    std::uint8_t                    unk000[0x440];  // 000
    SimpleListNode<const char*>     masters;        // 440
    SimpleListNode<MasterFileSize*> mastersData;    // 450
};
static_assert(offsetof(TESFile, masters) == 0x440, "TESFile::masters offset");
static_assert(offsetof(TESFile, mastersData) == 0x450, "TESFile::mastersData offset");
