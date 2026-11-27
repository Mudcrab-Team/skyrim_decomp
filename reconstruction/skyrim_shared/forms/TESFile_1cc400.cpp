// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1cc400 TESFile::IsMasterFilesValid
// Adapted bodies: none
#include "TESFile_1cc400.h"

// Checks whether any master file is missing or differs from its recorded size.
bool TESFile::IsMasterFilesValid() const
{
    const SimpleListNode<const char*>* masterNode = &masters;
    bool invalid = false;
    const SimpleListNode<MasterFileSize*>* dataNode = &mastersData;
    while (masterNode && masterNode->item && dataNode && dataNode->item) {
        char path[260];
        FormatPath(path, sizeof(path), kMasterFilePathFormat, masterNode->item);
        const MasterFileSize* expected = dataNode->item;
        WIN32_FIND_DATAA findData;
        void* handle = FindFirstFileA(path, &findData);
        if (handle != reinterpret_cast<void*>(-1)) {
            FindClose(handle);
            if (findData.nFileSizeLow != expected->low || findData.nFileSizeHigh != expected->high) {
                invalid = true;
            }
        } else {
            if (expected->low != 0 || expected->high != 0) {
                invalid = true;
            }
        }
        masterNode = masterNode->next;
        dataNode = dataNode->next;
    }
    return invalid;
}
