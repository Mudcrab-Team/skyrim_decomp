// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESDataHandler, TESDataHandler::CountFiles, TESDataHandler::files, TESFile: CRASHLOGGER_PDB(59818@2026.10.24)
// TESDataHandler::unk000, TESFile::IsMaster, TESFile::IsChecked, TESFile::IsActive, SimpleListNode, SimpleListNode::item, SimpleListNode::next: GUESS(low); offsets and predicate calls observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

class TESFile
{
public:
    bool IsMaster() const;
    bool IsChecked() const;
    bool IsActive() const;
};

template <class T>
struct SimpleListNode
{
    T               item;  // 00
    SimpleListNode* next;  // 08
};

class TESDataHandler
{
public:
    std::uint32_t CountFiles(std::int32_t a_filter) const;

    std::uint8_t             unk000[0xD60];  // 000
    SimpleListNode<TESFile*> files;          // D60
};
static_assert(offsetof(TESDataHandler, files) == 0xD60, "TESDataHandler::files offset");
