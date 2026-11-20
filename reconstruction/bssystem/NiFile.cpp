// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xeaf5b0 NiFile::good
// 0xeadd20 NiFile::size
#include "NiFile.h"

// ftell, fseek: GUESS(low); C runtime calls the listing makes, declared here without the C library header;
// the compare binds each call by position.
extern "C" __declspec(dllimport) long __cdecl ftell(void* a_file);
extern "C" __declspec(dllimport) int __cdecl fseek(void* a_file, long a_offset, int a_origin);

namespace
{
    constexpr int kSeekSet = 0;
    constexpr int kSeekEnd = 2;
}

// TODO body: RVA 0xeaf5b0, 5 bytes, NiFile::good.
bool NiFile::good() const
{
    return good44;
}

// Reads the current position, seeks past the end to measure the stream, then restores the position.
std::uint32_t NiFile::size() const
{
    const long position = ftell(file);
    if (position < 0) {
        return 0;
    }

    fseek(file, 0, kSeekEnd);
    const long end = ftell(file);
    fseek(file, position, kSeekSet);

    if (end < 0) {
        return 0;
    }
    return static_cast<std::uint32_t>(end);
}
