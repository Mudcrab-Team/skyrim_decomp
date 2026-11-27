// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESDataHandler, TESDataHandler::FindModByFileName_14016D1B0, TESDataHandler::files, TESFile, TESFile::fileName: CRASHLOGGER_PDB(59818@2026.10.24)
// TESDataHandler::unk000, TESFile::unk000, SimpleListNode, SimpleListNode::item, SimpleListNode::next: GUESS(low); offsets and list layout observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile
{
public:
    std::uint8_t unk000[0x58];   // 000
    char         fileName[260];  // 058
};
static_assert(offsetof(TESFile, fileName) == 0x58, "TESFile::fileName offset");

template <class T>
struct SimpleListNode
{
    T               item;  // 00
    SimpleListNode* next;  // 08
};

class TESDataHandler
{
public:
    TESFile* FindModByFileName_14016D1B0(const char* a_fileName) const;

    std::uint8_t             unk000[0xD60];  // 000
    SimpleListNode<TESFile*> files;          // D60
};
static_assert(offsetof(TESDataHandler, files) == 0xD60, "TESDataHandler::files offset");
