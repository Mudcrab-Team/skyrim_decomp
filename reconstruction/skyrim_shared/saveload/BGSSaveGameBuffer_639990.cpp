// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: reconstruction from pinned-image observations; see Adapted bodies.
// Adapted bodies: WriteRaw, treated as adapted: it has the shape of the stream WriteValue helper, for which the origin check reports similar sibling bodies (cited below, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// SPDX-License-Identifier: CC0-1.0
// BGSSaveGameBuffer: CRASHLOGGER_PDB(59818@2026.10.24)
// WriteToFile, WriteRaw: GUESS(low)
// 0x639990 BGSSaveGameBuffer::WriteToFile
#include "BGSSaveGameBuffer_639990.h"

namespace
{
inline void WriteRaw(SaveFile639990* a_file, const void* a_data, std::uint32_t a_len)
{
    std::uint32_t elemSize = 1;
    std::uint32_t written = a_file->writeFn(a_file, a_data, a_len, &elemSize, 1);
    a_file->bytesWritten += written;
}
}

// Writes the save buffer length and payload bytes to the save file stream.
// The CrashLogger name is sub_140599840; the name used here is a guess from what the body does.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BGSSaveGameBuffer::WriteToFile(SaveFile639990* a_file)
{
    a_file->WriteHeader(&size, 4);
    std::uint32_t len = size;
    if (gSaveManager->skipPayload)
    {
        if (len != 0)
        {
            WriteRaw(a_file, nullptr, len);
        }
    }
    else if (buffer != nullptr && len != 0)
    {
        WriteRaw(a_file, buffer, len);
    }
}
