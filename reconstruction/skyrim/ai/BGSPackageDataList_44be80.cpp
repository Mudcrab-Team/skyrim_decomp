// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSPackageDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function44be80: GUESS(low); provisional member name
// 0x44be80 BGSPackageDataList::Function44be80
// CI hash: 0x44be80 ?Function44be80@BGSPackageDataList@@QEAA_NEPEAUPackageValue@@@Z
#include "BGSPackageDataList_44be80.h"

// Guess: Replace the owned package value for a tag.
bool BGSPackageDataList::Function44be80(unsigned char tag, PackageValue* value)
{
    bool found = false;
    for (unsigned i = 0; i < count; ++i) {
        if (tags[i] == tag) {
            delete values[i];
            values[i] = value;
            found = true;
            i = count;
        }
    }
    return found;
}
