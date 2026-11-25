// Near miss: 0.0% | other
// BSResourceNiBinaryStream: tell, good, SetEndianSwap, deleting destructor, get_info.
// Build sse-steam-1-7-104.
//
// RVA 0xf01650, 4 bytes: BSResourceNiBinaryStream::tell
// RVA 0xf01600, 9 bytes: BSResourceNiBinaryStream::good
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0xf011e0 BSResourceNiBinaryStream::BSResourceNiBinaryStream

#include "include/f011e0/BSResourceNiBinaryStream.h"

BSResourceNiBinaryStream::BSResourceNiBinaryStream()
{
	stream.ptr = nullptr;
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


// OpenStreamByName, opened, failed, current, previous, next: GUESS(low)
std::uint32_t OpenStreamByName(const char*, BSResource::Stream**, bool, BSResource::Location*);
BSResourceNiBinaryStream::BSResourceNiBinaryStream(const char* a_name, bool a_writeable, BSResource::Location* a_optionalStart)
    : stream(), buffer(nullptr), streamPos(0), lastError(0)
{
	_readFn = ReadNoSwap;
	_writeFn = WriteNoSwap;

	if (OpenStreamByName(a_name, &stream.ptr, a_writeable, a_optionalStart) == 0) {
		BSResource::Stream* opened = stream;
		std::uint32_t current;
		// The target uses an atomic compare exchange loop.
		do {
			current = opened->refCount;
		} while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&opened->refCount), static_cast<long>(current | 0xa), static_cast<long>(current)) != static_cast<long>(current));
		opened->Unk_01();
	} else if (stream != nullptr) {
		BSResource::Stream* failed = stream;
		stream.ptr = nullptr;
        long current = static_cast<long>(failed->refCount);
        long previous;
        long next;
        do {
            previous = current;
            next = previous - 0x1000;
            current = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&failed->refCount), next, previous);
        } while (current != previous);
		if ((next & 0xfffff000) == 0) {
			delete failed;
		}
	}
}



// tlsSlot, StreamTlsScope, ::saved, category, allocationSize, referenced, guard,
// flags, size, memory, opened, current: GUESS(low); allocation category and local names.
extern __declspec(thread) std::uint32_t tlsSlot;
struct StreamTlsScope {
    std::uint32_t saved;
    StreamTlsScope() : saved(tlsSlot) { tlsSlot = 10; }
    ~StreamTlsScope() { tlsSlot = saved; }
};
// AllocateStreamBuffer, AllocateFallback: GUESS(low); observed allocation targets.
void* AllocateStreamBuffer(std::uint32_t);
void* AllocateFallback(std::uint64_t);
BSResourceNiBinaryStream::BSResourceNiBinaryStream(BSResource::Stream** a_source, bool a_write, bool a_buffered)
: stream(*a_source), buffer(nullptr), streamPos(0), lastError(0)
{
    StreamTlsScope category;
    // Read the thread local storage pointer.
    auto opened = *a_source;
    std::uint32_t current;
    if (a_buffered) {
        // Use the target atomic compare exchange.
        do { current = opened->refCount; } while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&opened->refCount), current | 8, current) != static_cast<long>(current));
        opened->Unk_01();
    }
    if (a_buffered) {
        std::uint32_t size = 0x10000;
        if (a_write && !((*a_source)->refCount & 1)) size = (*a_source)->totalSize;
        if (size) {
            std::uint64_t allocationSize = static_cast<std::uint64_t>(size) + 0x38;
            void* memory = nullptr;
            if (a_write) memory = AllocateStreamBuffer(static_cast<std::uint32_t>(allocationSize));
            if (!memory) memory = AllocateFallback(allocationSize);
            if (memory) {
                buffer = static_cast<StreamBuffer*>(memory);
                buffer->owner = *a_source;
                buffer->begin = 0;
                buffer->limit = 0;
                buffer->position = 0;
                *reinterpret_cast<std::uint32_t*>(&buffer->unk20) = size;
                buffer->data = static_cast<char*>(memory) + 0x38;
                buffer->flags = ((*a_source)->refCount & 1) * 2;
            }
        }
    }
    else {
        std::uint32_t flags = a_write ? 14 : 8;
        // Use the target atomic compare exchange.
        do { current = opened->refCount; } while (_InterlockedCompareExchange(reinterpret_cast<volatile long*>(&opened->refCount), current | flags, current) != static_cast<long>(current));
        opened->Unk_01();
    }
    _readFn = ReadNoSwap;
    _writeFn = WriteNoSwap;
}
