// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ArchiveFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioneb97c0: GUESS(low); provisional member name
// 0xeb97c0 ArchiveFile::Functioneb97c0
// CI hash: 0xeb97c0 ?Functioneb97c0@ArchiveFile@@QEAAIPEAXI@Z
#include "ArchiveFile_eb97c0.h"

// Guess: Read within the archive file length and advance the position.
unsigned ArchiveFile::Functioneb97c0(void* output, unsigned count)
{
    if (position + count > length) {
        if (position > length) { position = length; count = 0; }
        else { count = length - position; }
    }
    unsigned read = Read(output, count);
    position += read;
    return read;
}
