// Source exposure: binary-analysis (class layout and the table name are observed from the listing).
// Code origin: original body written from the local listing; no community declarations used.
// BSEffectShaderPropertyColorController: EXE_RTTI
// GetCtlrID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
#pragma once

#include <cstdint>

// kEffectColorCtlrIDs: GUESS(low); table of controller-ID strings indexed by the controlled variable
extern const char* const kEffectColorCtlrIDs[];

class BSEffectShaderPropertyColorController
{
public:
    const char* GetCtlrID();

    // controlledVariable: GUESS(low); offset 0x50 observed from the listing
    std::uint8_t unk00[0x50];
    std::uint32_t controlledVariable;
};
