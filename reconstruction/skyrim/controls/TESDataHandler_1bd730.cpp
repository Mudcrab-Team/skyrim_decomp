// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1bd730 TESDataHandler::FindModByFileName_14016D1B0
// Adapted bodies: none
#include "TESDataHandler_1bd730.h"

#include <cstring>

// Searches the loaded file list for a TESFile matching a_fileName case-insensitively.
TESFile* TESDataHandler::FindModByFileName_14016D1B0(const char* a_fileName) const
{
    const SimpleListNode<TESFile*>* node = &files;
    if (!a_fileName) {
        return nullptr;
    }
    while (node && node->item) {
        TESFile* file = node->item;
        if (_stricmp(a_fileName, file->fileName) == 0) {
            return file;
        }
        node = node->next;
    }
    return nullptr;
}
