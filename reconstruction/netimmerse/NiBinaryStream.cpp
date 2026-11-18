// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0xeae190 NiBinaryStream::get_info
// 0xeae130 NiBinaryStream::ctor
#include "NiBinaryStream.h"

void NiBinaryStream::get_info(BufferInfo& a_buf)
{
    a_buf.data = 0;
    a_buf.size = 0;
    a_buf.capacity = 0;
    a_buf.flags = 0;
}

NiBinaryStream::NiBinaryStream()
{
    unknown10 = 0;
    unknown18 = 0;
    unknown08 = 0;
}
