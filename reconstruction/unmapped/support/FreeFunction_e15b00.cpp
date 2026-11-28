// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xe15b00 Functione15b00
// Adapted bodies: none
#include "FreeFunction_e15b00.h"

// Flushes the read or write buffer of bufferedFile according to its active mode.
void Functione15b00(BufferedFile_e15b00* bufferedFile)
{
    switch (bufferedFile->mode) {
        case 1:
            if (bufferedFile->limit != bufferedFile->pos) {
                bufferedFile->fileOffset = bufferedFile->file->Seek(
                    static_cast<std::int64_t>(bufferedFile->pos - bufferedFile->limit), 1);
            }
            bufferedFile->pos = 0;
            bufferedFile->limit = 0;
            break;
        case 2:
            bufferedFile->fileOffset += bufferedFile->file->Write(bufferedFile->buffer, bufferedFile->pos);
            bufferedFile->pos = 0;
            break;
        default:
            break;
    }
}
