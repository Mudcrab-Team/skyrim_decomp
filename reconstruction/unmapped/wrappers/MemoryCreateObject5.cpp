// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
// 0x98d470 MemoryCreateObject5::Op98d470
// 0x98d600 MemoryCreateObject5::Op98d600
// 0xee9af0 MemoryCreateObject5::Opee9af0
// 0xee9b50 MemoryCreateObject5::Opee9b50
// 0xee9bb0 MemoryCreateObject5::Opee9bb0
// 0xf7e0d0 MemoryCreateObject5::Opf7e0d0
// 0xfed2a0 MemoryCreateObject5::Opfed2a0
// 0xfed300 MemoryCreateObject5::Opfed300
// 0x1168e00 MemoryCreateObject5::Op1168e00
// 0x1168f20 MemoryCreateObject5::Op1168f20
// 0x12185b0 MemoryCreateObject5::Op12185b0
// 0x121aeb0 MemoryCreateObject5::Op121aeb0
#include "MemoryCreateObject5.h"

void* MemoryCreateObject5::Op98d470()
{
    return new Obj_98d470();
}

void* MemoryCreateObject5::Op98d600()
{
    return new Obj_98d600();
}

void* MemoryCreateObject5::Opee9af0()
{
    Obj_ee9af0* p = static_cast<Obj_ee9af0*>(MemoryFactoryManager::Alloc(sizeof(Obj_ee9af0)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Opee9b50()
{
    Obj_ee9b50* p = static_cast<Obj_ee9b50*>(MemoryFactoryManager::Alloc(sizeof(Obj_ee9b50)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Opee9bb0()
{
    Obj_ee9bb0* p = static_cast<Obj_ee9bb0*>(MemoryFactoryManager::Alloc(sizeof(Obj_ee9bb0)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Opf7e0d0()
{
    Obj_f7e0d0* p = static_cast<Obj_f7e0d0*>(MemoryFactoryManager::Alloc(sizeof(Obj_f7e0d0)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Opfed2a0()
{
    Obj_fed2a0* p = static_cast<Obj_fed2a0*>(MemoryFactoryManager::Alloc(sizeof(Obj_fed2a0)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Opfed300()
{
    Obj_fed300* p = static_cast<Obj_fed300*>(MemoryFactoryManager::Alloc(sizeof(Obj_fed300)));
    if (p) {
        p->f_0 = 0u;
        p->f_8 = 0u;
        p->f_10 = 0u;
        return p;
    }
    return nullptr;
}

void* MemoryCreateObject5::Op1168e00()
{
    return new Obj_1168e00();
}

void* MemoryCreateObject5::Op1168f20()
{
    return new Obj_1168f20();
}

void* MemoryCreateObject5::Op12185b0()
{
    return new Obj_12185b0();
}

void* MemoryCreateObject5::Op121aeb0()
{
    return new Obj_121aeb0();
}

