// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSPackageDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function44bdc0: GUESS(low); provisional member name
// 0x44bdc0 BGSPackageDataList::Function44bdc0
// CI hash: 0x44bdc0 ?Function44bdc0@BGSPackageDataList@@QEAAXE@Z
#include "BGSPackageDataList_44bdc0.h"

// Guess: Erase an owned package value and shift its paired tags.
void BGSPackageDataList::Function44bdc0(unsigned char tag)
{
    for (unsigned i = 0; i < count; ++i) {
        if (tags[i] == tag) {
            PackageValue* removed = values[i];
            for (unsigned j = i + 1; j < count; ++j) {
                values[j - 1] = values[j];
                tags[j - 1] = tags[j];
            }
            delete removed;
            i = count;
            --count;
        }
    }
}
