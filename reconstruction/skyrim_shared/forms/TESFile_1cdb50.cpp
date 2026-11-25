// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cdb50: GUESS(low); provisional member name
// 0x1cdb50 TESFile::Function1cdb50
// CI hash: 0x1cdb50 ?Function1cdb50@TESFile@@QEAAIPEAEI@Z
#include "TESFile_1cdb50.h"

// Guess: Copy the current record header and payload when the caller buffer is large enough.
unsigned TESFile::Function1cdb50(unsigned char* output, unsigned capacity)
{
    if (!output || !capacity) { return 0; }
    if (!record.type && !Prepare()) { return 0; }
    unsigned required = record.size + 24;
    if (required > capacity) { return 0; }
    *reinterpret_cast<Record1cdb50*>(output) = record;
    Seek(offset + 24, origin1cdb50);
    if (Read(output + 24, record.size) != record.size) { return 0; }
    return required;
}
