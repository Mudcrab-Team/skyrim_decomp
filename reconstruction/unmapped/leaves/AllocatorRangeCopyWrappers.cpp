// SPDX-License-Identifier: CC0-1.0
// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: published target bounds
// Code origin: original range-copy wrapper template.
// AllocatorRangeCopyWrappers, methods and callees: GUESS(low) STANDIN; original element types and owners unknown.
// Adapted bodies: none
// 0x10ee90 AllocatorRangeCopyWrappers::Copy10ee90
// 0x115c20 AllocatorRangeCopyWrappers::Copy115c20
// 0x117290 AllocatorRangeCopyWrappers::Copy117290
// 0x118100 AllocatorRangeCopyWrappers::Copy118100
// 0x11ad50 AllocatorRangeCopyWrappers::Copy11ad50
// 0x11e050 AllocatorRangeCopyWrappers::Copy11e050
// 0x11e8d0 AllocatorRangeCopyWrappers::Copy11e8d0
// 0x11ea90 AllocatorRangeCopyWrappers::Copy11ea90
// 0x11fb00 AllocatorRangeCopyWrappers::Copy11fb00
// 0x121e30 AllocatorRangeCopyWrappers::Copy121e30
// 0x12cce0 AllocatorRangeCopyWrappers::Copy12cce0
// 0x12ce50 AllocatorRangeCopyWrappers::Copy12ce50
// 0x12fff0 AllocatorRangeCopyWrappers::Copy12fff0
// 0x130180 AllocatorRangeCopyWrappers::Copy130180
// 0x130310 AllocatorRangeCopyWrappers::Copy130310
// 0x134910 AllocatorRangeCopyWrappers::Copy134910
// 0x1352d0 AllocatorRangeCopyWrappers::Copy1352d0
// 0x136670 AllocatorRangeCopyWrappers::Copy136670
// 0x1367e0 AllocatorRangeCopyWrappers::Copy1367e0
// 0x138200 AllocatorRangeCopyWrappers::Copy138200
// 0x138cc0 AllocatorRangeCopyWrappers::Copy138cc0
// 0x139410 AllocatorRangeCopyWrappers::Copy139410
// 0x13d170 AllocatorRangeCopyWrappers::Copy13d170
// 0x13ef00 AllocatorRangeCopyWrappers::Copy13ef00
// 0x140ff0 AllocatorRangeCopyWrappers::Copy140ff0
// 0x143b30 AllocatorRangeCopyWrappers::Copy143b30
// CI hash: 0x10ee90 ?Copy10ee90@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x115c20 ?Copy115c20@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x117290 ?Copy117290@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x118100 ?Copy118100@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x11ad50 ?Copy11ad50@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x11e050 ?Copy11e050@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x11e8d0 ?Copy11e8d0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x11ea90 ?Copy11ea90@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x11fb00 ?Copy11fb00@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x121e30 ?Copy121e30@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x12cce0 ?Copy12cce0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x12ce50 ?Copy12ce50@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x12fff0 ?Copy12fff0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x130180 ?Copy130180@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x130310 ?Copy130310@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x134910 ?Copy134910@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x1352d0 ?Copy1352d0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x136670 ?Copy136670@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x1367e0 ?Copy1367e0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x138200 ?Copy138200@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x138cc0 ?Copy138cc0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x139410 ?Copy139410@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x13d170 ?Copy13d170@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x13ef00 ?Copy13ef00@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x140ff0 ?Copy140ff0@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
// CI hash: 0x143b30 ?Copy143b30@AllocatorRangeCopyWrappers@@SAPEAEPEAXPEBE1PEAE@Z
#include "AllocatorRangeCopyWrappers.h"

unsigned char* AllocatorRangeCopyWrappers::Copy10ee90(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy115c20(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy117290(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy118100(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy11ad50(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy11e050(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy11e8d0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy11ea90(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy11fb00(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy121e30(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy12cce0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy12ce50(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy12fff0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy130180(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy130310(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy134910(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy1352d0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy136670(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy1367e0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy138200(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy138cc0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy139410(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy13d170(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy13ef00(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy140ff0(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}

unsigned char* AllocatorRangeCopyWrappers::Copy143b30(void* unused, const unsigned char* first, const unsigned char* last, unsigned char* dest)
{
    (void)unused;
    unsigned long long count = static_cast<unsigned long long>(last - first);
    RangeCopyTarget15a97f2(dest, first, count);
    return dest + count;
}
