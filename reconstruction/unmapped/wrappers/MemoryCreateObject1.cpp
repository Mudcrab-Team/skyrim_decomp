// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x1d0f50 MemoryCreateObject1::Op1d0f50
// 0x1d6ab0 MemoryCreateObject1::Op1d6ab0
// 0x2d4840 MemoryCreateObject1::Op2d4840
// 0x2d48a0 MemoryCreateObject1::Op2d48a0
// 0x2d4900 MemoryCreateObject1::Op2d4900
// 0x2d4960 MemoryCreateObject1::Op2d4960
// 0x2dcb90 MemoryCreateObject1::Op2dcb90
// 0x2fa450 MemoryCreateObject1::Op2fa450
// 0x3149c0 MemoryCreateObject1::Op3149c0
// 0x44fd40 MemoryCreateObject1::Op44fd40
// 0x44fe60 MemoryCreateObject1::Op44fe60
// 0x44ff80 MemoryCreateObject1::Op44ff80
// 0x459850 MemoryCreateObject1::Op459850
// 0x4598b0 MemoryCreateObject1::Op4598b0
// 0x459980 MemoryCreateObject1::Op459980
// 0x459b10 MemoryCreateObject1::Op459b10
// 0x459b80 MemoryCreateObject1::Op459b80
// 0x459c40 MemoryCreateObject1::Op459c40
// 0x459e30 MemoryCreateObject1::Op459e30
// 0x45a1f0 MemoryCreateObject1::Op45a1f0
// 0x45a400 MemoryCreateObject1::Op45a400
// 0x45a590 MemoryCreateObject1::Op45a590
// 0x52f870 MemoryCreateObject1::Op52f870
// 0x7d48a0 MemoryCreateObject1::Op7d48a0
// 0x7d4900 MemoryCreateObject1::Op7d4900
// 0x7d4960 MemoryCreateObject1::Op7d4960
// 0x7d49c0 MemoryCreateObject1::Op7d49c0
// 0x7d4a20 MemoryCreateObject1::Op7d4a20
// 0x7d4a80 MemoryCreateObject1::Op7d4a80
// 0x7d4ae0 MemoryCreateObject1::Op7d4ae0
#include "MemoryCreateObject1.h"

void* MemoryCreateObject1::Op1d0f50()
{
    Obj_1d0f50* p = static_cast<Obj_1d0f50*>(MemoryFactoryManager::Alloc(sizeof(Obj_1d0f50)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject1::Op1d6ab0()
{
    return new Obj_1d6ab0();
}

void* MemoryCreateObject1::Op2d4840()
{
    return new Obj_2d4840();
}

void* MemoryCreateObject1::Op2d48a0()
{
    return new Obj_2d48a0();
}

void* MemoryCreateObject1::Op2d4900()
{
    return new Obj_2d4900();
}

void* MemoryCreateObject1::Op2d4960()
{
    return new Obj_2d4960();
}

void* MemoryCreateObject1::Op2dcb90()
{
    return new Obj_2dcb90();
}

void* MemoryCreateObject1::Op2fa450()
{
    return new Obj_2fa450();
}

void* MemoryCreateObject1::Op3149c0()
{
    Obj_3149c0* p = static_cast<Obj_3149c0*>(MemoryFactoryManager::Alloc(sizeof(Obj_3149c0)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject1::Op44fd40()
{
    return new Obj_44fd40();
}

void* MemoryCreateObject1::Op44fe60()
{
    return new Obj_44fe60();
}

void* MemoryCreateObject1::Op44ff80()
{
    return new Obj_44ff80();
}

void* MemoryCreateObject1::Op459850()
{
    return new Obj_459850();
}

void* MemoryCreateObject1::Op4598b0()
{
    return new Obj_4598b0();
}

void* MemoryCreateObject1::Op459980()
{
    return new Obj_459980();
}

void* MemoryCreateObject1::Op459b10()
{
    return new Obj_459b10();
}

void* MemoryCreateObject1::Op459b80()
{
    return new Obj_459b80();
}

void* MemoryCreateObject1::Op459c40()
{
    return new Obj_459c40();
}

void* MemoryCreateObject1::Op459e30()
{
    return new Obj_459e30();
}

void* MemoryCreateObject1::Op45a1f0()
{
    return new Obj_45a1f0();
}

void* MemoryCreateObject1::Op45a400()
{
    return new Obj_45a400();
}

void* MemoryCreateObject1::Op45a590()
{
    return new Obj_45a590();
}

void* MemoryCreateObject1::Op52f870()
{
    Obj_52f870* p = static_cast<Obj_52f870*>(MemoryFactoryManager::Alloc(sizeof(Obj_52f870)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject1::Op7d48a0()
{
    return new Obj_7d48a0();
}

void* MemoryCreateObject1::Op7d4900()
{
    return new Obj_7d4900();
}

void* MemoryCreateObject1::Op7d4960()
{
    return new Obj_7d4960();
}

void* MemoryCreateObject1::Op7d49c0()
{
    return new Obj_7d49c0();
}

void* MemoryCreateObject1::Op7d4a20()
{
    return new Obj_7d4a20();
}

void* MemoryCreateObject1::Op7d4a80()
{
    return new Obj_7d4a80();
}

void* MemoryCreateObject1::Op7d4ae0()
{
    return new Obj_7d4ae0();
}

