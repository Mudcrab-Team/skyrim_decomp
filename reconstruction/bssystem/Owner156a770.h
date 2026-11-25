// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation and partial layouts from the pinned accesses and cited declarations. Stamped as a twin of matched 0x156aaf0 (bssystem/NiMemStream_156a9e0): source copied, names replaced by placeholders.
// ::position, ::length, ::capacity, ::externalBuffer, ::released, ::ReleaseBuffer: GUESS(low)
// FreeStreamBuffer_156a770, Function156a770, Owner156a770: GUESS(low) STANDIN
// get_info, seek: GUESS(low) STANDIN
#pragma once
#include "NiMemStream_156a9e0.h"
#include <cstring>

class Owner156a770 : public NiBinaryStream
{
public:
    ~Owner156a770() override;
    void get_info(BufferInfo& info) override;
    void seek(std::int32_t delta) override;
    void* ReleaseBuffer();
    std::uint32_t Function156a770(void* destination, std::uint32_t count);

private:
    unsigned char* buffer;
    std::uint32_t position;
    std::uint32_t length;
    std::uint32_t capacity;
    bool externalBuffer;
    bool released;
};

