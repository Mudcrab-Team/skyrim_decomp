// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// 0x1beba0 TESDataHandler::CountFiles
// Adapted bodies: none
#include "TESDataHandler_1beba0.h"

// Counts TESFile entries in the file list matching the requested filter mode.
std::uint32_t TESDataHandler::CountFiles(std::int32_t a_filter) const
{
    std::uint32_t count = 0;
    const SimpleListNode<TESFile*>* node = &files;
    while (node) {
        TESFile* file = node->item;
        if (!file) {
            break;
        }
        switch (a_filter) {
        case 0:
            if (file->IsChecked()) {
                ++count;
            }
            break;
        case 1:
            if (file->IsMaster() && file->IsChecked()) {
                ++count;
            }
            break;
        case 2:
            if (!file->IsMaster() && file->IsChecked()) {
                ++count;
            }
            break;
        case 3:
            if (!file->IsMaster() && file->IsActive()) {
                ++count;
            }
            break;
        }
        node = node->next;
    }
    return count;
}
