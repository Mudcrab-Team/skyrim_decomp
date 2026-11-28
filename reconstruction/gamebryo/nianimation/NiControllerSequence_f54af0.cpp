// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf54af0 NiControllerSequence::RegisterStreamables_140CC5080
#include "NiControllerSequence_f54af0.h"

// Register the sequence's interpolators, controllers, ID tag strings, text keys, and anim notes.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool NiControllerSequence::RegisterStreamables_140CC5080(NiStreamf54af0& a_stream)
{
    if (!NiObjectf54af0::RegisterStreamables(a_stream)) {
        return false;
    }

    for (std::uint32_t i = 0; i < arraySize; ++i) {
        InterpArrayItemf54af0& item = interpArray[i];
        if (item.interp) {
            item.interp->RegisterStreamables(a_stream);
        }
        if (item.controller) {
            item.controller->RegisterStreamables(a_stream);
        }
        IDTagf54af0& tag = idTags[i];
        a_stream.RegisterFixedString(tag.avObjectName);
        a_stream.RegisterFixedString(tag.propertyType);
        a_stream.RegisterFixedString(tag.ctlrType);
        a_stream.RegisterFixedString(tag.ctlrID);
        a_stream.RegisterFixedString(tag.interpolatorID);
    }

    if (textKeys) {
        textKeys->RegisterStreamables(a_stream);
    }

    a_stream.RegisterFixedString(name);
    a_stream.RegisterFixedString(accumRootName);

    for (std::uint16_t i = 0; i < animNotesCount; ++i) {
        animNotes[i]->RegisterStreamables(a_stream);
    }

    return true;
}
