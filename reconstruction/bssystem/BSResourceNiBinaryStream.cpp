// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names from CommonLibSSE-NG b93280e (MIT).
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none other above its threshold at the pinned checkouts.
// 0xf01650 BSResourceNiBinaryStream::tell
// 0xf01600 BSResourceNiBinaryStream::good
// 0xf016e0 BSResourceNiBinaryStream::set_endian_swap
// 0xf01be0 BSResourceNiBinaryStream::~BSResourceNiBinaryStream
// 0xf01660 BSResourceNiBinaryStream::get_info
// 0xf014c0 BSResourceNiBinaryStream::Dtor
#include "BSResourceNiBinaryStream.h"

BSResourceNiBinaryStream::BSResourceNiBinaryStream()
{
	stream = nullptr;
	buffer = nullptr;
	streamPos = 0;
	lastError = 0;
}

bool BSResourceNiBinaryStream::good() const
{
	return stream != nullptr;
}

std::uint32_t BSResourceNiBinaryStream::tell() const
{
	return streamPos;
}

void BSResourceNiBinaryStream::set_endian_swap(bool a_doSwap)
{
	if (a_doSwap) {
		_readFn = ReadSwap;
		_writeFn = WriteSwap;
	} else {
		_readFn = ReadNoSwap;
		_writeFn = WriteNoSwap;
	}
}

void BSResourceNiBinaryStream::get_info(BufferInfo& a_buf)
{
	a_buf.buffer = nullptr;
	a_buf.totalSize = stream ? stream->totalSize : 0;
	if (buffer) {
		// FillInfo: GUESS(low) OBSERVED; the call passes streamPos and lastError together as one 8-byte value
		buffer->FillInfo(&a_buf, &a_buf.bufferReadSize, *reinterpret_cast<const std::uint64_t*>(&streamPos));
		a_buf.bufferAllocSize = a_buf.bufferReadSize;
		buffer->flags &= ~1u;
	} else {
		a_buf.bufferAllocSize = 0;
		a_buf.bufferReadSize = 0;
		a_buf.bufferPos = 0;
	}
	a_buf.streamPos = streamPos;
}
