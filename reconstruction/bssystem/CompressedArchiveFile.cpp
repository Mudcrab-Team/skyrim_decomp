// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing unit plus original reconstruction of archive stream helpers.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CompressedReadFn, CompressedWriteFn, SetEndianSwapFallback: GUESS(low)
// 0xeb9ee0 CompressedArchiveFile::Unk_0A
// 0xeb9ea0 CompressedArchiveFile::seek(std::int32_t)
// 0xeb9ef0 CompressedArchiveFile::Functioneb9ef0
// 0xeb9f10 CompressedArchiveFile::Functioneb9f10
// 0xeb9f40 CompressedArchiveFile::Functioneb9f40
#include "CompressedArchiveFile.h"

void CompressedReadFn();
void CompressedWriteFn();
void SetEndianSwapFallback(CompressedArchiveFile* a_self, bool a_doSwap);

std::uint32_t CompressedArchiveFile::Unk_0A() const
{
    return member;
}

void CompressedArchiveFile::seek(std::int32_t a_numBytes)
{
    seek(a_numBytes, 1);
}

std::uint32_t CompressedArchiveFile::Functioneb9ef0() const
{
    return member;
}

bool CompressedArchiveFile::Functioneb9f10() const
{
    return streamPtr != nullptr;
}

void CompressedArchiveFile::Functioneb9f40(bool a_doSwap)
{
    if (a_doSwap) {
        SetEndianSwapFallback(this, a_doSwap);
        return;
    }
    readFn = reinterpret_cast<void*>(&CompressedReadFn);
    writeFn = reinterpret_cast<void*>(&CompressedWriteFn);
}
