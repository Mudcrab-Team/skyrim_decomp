// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x389800 BGSAssociationType::~BGSAssociationType
// 0x389430 BGSAssociationType::InitializeData
#include "BGSAssociationType.h"
BGSAssociationType::BGSAssociationType() {}
BGSAssociationType::~BGSAssociationType() { TESForm::ClearData(); }
// current, rows, columns: GUESS(low); traverse the two association-name pairs.
void BGSAssociationType::InitializeData() {
    flags=0;
    auto* current=&names[0];
    for (std::size_t rows=2; rows; --rows) {
        for (std::size_t columns=2; columns; --columns) {
            *current=BSFixedString(nullptr);
            ++current;
        }
    }
}
