// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x264820 BGSOutfit::ClearData
// 0x264d80 BGSOutfit::~BGSOutfit
#include "BGSOutfit.h"
extern __declspec(thread) std::uint32_t OutfitTLS;
struct OutfitScope {
    std::uint32_t saved;
    OutfitScope() : saved(OutfitTLS) { OutfitTLS=0x65; }
    ~OutfitScope() { OutfitTLS=saved; }
};
void BGSOutfit::ClearData() {
    OutfitScope scope;
    // array: GUESS(low); hold the represented member address across cleanup.
    auto* array=&items;
    if (array->data) { ClearOutfitArray(array); array->count=0; }
}
