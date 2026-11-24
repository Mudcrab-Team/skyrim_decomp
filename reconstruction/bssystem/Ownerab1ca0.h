// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: Stamped as a twin of matched 0xf01650 (bssystem/BSResourceNiBinaryStream): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// BufferInfo: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Stream, StreamBuffer: STANDIN GUESS(low); BSResource::Stream is the NG name of the pointee, its members are unnamed here
// Ownerab1ca0: GUESS(low) STANDIN
// NiBinaryStream, good, seek, tell, get_info, set_endian_swap, buffer, streamPos, stream, lastError: GUESS(low) STANDIN
#pragma once
#include "BSResourceNiBinaryStream.h"

class Ownerab1ca0 : public NiBinaryStream
{
public:
	Ownerab1ca0();
	~Ownerab1ca0() override;  // 00

	bool          good() const override;                    // 01
	void          seek(std::int32_t a_numBytes) override;   // 02
	std::uint32_t tell() const override;                    // 03
	void          get_info(BufferInfo& a_buf) override;     // 04
	void          set_endian_swap(bool a_doSwap) override;  // 05

	BSResource::Stream* stream;     // 20
	StreamBuffer*       buffer;     // 28
	std::uint32_t       streamPos;  // 30
	std::uint32_t       lastError;  // 34
};
static_assert(sizeof(Ownerab1ca0) == 0x38, "Ownerab1ca0 size");
