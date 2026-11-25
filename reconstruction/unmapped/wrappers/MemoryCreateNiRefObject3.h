// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateNiRefObject3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>
#include <intrin.h>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_17fffb8[1];
    extern long NiRefCount_331c620;
    extern std::uint8_t Data_194b6f0[1];
    extern std::uint8_t Data_194b868[1];
    extern std::uint8_t Data_194ba00[1];
    extern std::uint8_t Data_194bb78[1];
    extern std::uint8_t Data_194bcf0[1];
    extern std::uint8_t Data_194bf20[1];
    extern std::uint8_t Data_194c020[1];
    extern std::uint8_t Data_194c120[1];
    extern std::uint8_t Data_194c2b8[1];
    extern std::uint8_t Data_194c4d0[1];
    extern std::uint8_t Data_194c590[1];
    extern std::uint8_t Data_194c670[1];
    extern std::uint8_t Data_194c790[1];
    extern std::uint8_t Data_194c890[1];
    extern std::uint8_t Data_194c990[1];
    extern std::uint8_t Data_194cab0[1];
    extern std::uint8_t Data_194cbb0[1];
    extern std::uint8_t Data_194cd18[1];
    extern std::uint8_t Data_194ce18[1];
    extern std::uint8_t Data_194cf38[1];
    extern std::uint8_t Data_194d038[1];
    extern std::uint8_t Data_194d198[1];
    extern std::uint8_t Data_194d2b8[1];
    extern std::uint8_t Data_194d378[1];
    extern std::uint8_t Data_194d498[1];
    extern std::uint8_t Data_194d598[1];
    extern std::uint8_t Data_194d6b8[1];
    extern std::uint8_t Data_194d798[1];
    extern std::uint8_t Data_194d8b8[1];
    extern std::uint8_t Data_194d9d8[1];
}

struct MemoryFactoryManager {
    static void* GetSingleton() {
        if (MemMgrGuard_369ac98 != 2u) {
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        }
        return MemMgrInst_369a810;
    }
    static void* Alloc(std::size_t size, std::uint32_t align = 0u, bool alignReq = false) {
        return MemMgrAlloc_cde250(GetSingleton(), size, align, alignReq);
    }
};

struct HeapAllocBase {
    static void* operator new(std::size_t size) throw() {
        return MemoryFactoryManager::Alloc(size);
    }
};

struct NiRefBase : HeapAllocBase {
    void* vftable;
    std::uint32_t refCount;
    std::uint32_t unk_c;
    NiRefBase() {
        vftable = Data_17fffb8;
        refCount = 0u;
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&NiRefCount_331c620));  // atomic object counter increment
    }
};

struct Obj_840bc0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_840bc0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d9d8;
    }
};

struct Obj_8414b0 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_8414b0() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194b6f0;
    }
};

struct Obj_841a30 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_841a30() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d8b8;
    }
};

struct Obj_841f70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_841f70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d798;
    }
};

struct Obj_8424c0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8424c0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d6b8;
    }
};

struct Obj_8428a0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8428a0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d598;
    }
};

struct Obj_842e10 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_842e10() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d498;
    }
};

struct Obj_843770 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_843770() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194b868;
    }
};

struct Obj_843b20 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_843b20() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d378;
    }
};

struct Obj_8440a0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8440a0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d2b8;
    }
};

struct Obj_844620 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_844620() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d198;
    }
};

struct Obj_844b40 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_844b40() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194d038;
    }
};

struct Obj_845020 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_845020() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194cf38;
    }
};

struct Obj_845860 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_845860() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194ba00;
    }
};

struct Obj_845d60 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_845d60() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ce18;
    }
};

struct Obj_846240 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_846240() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194cd18;
    }
};

struct Obj_846670 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_846670() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194cbb0;
    }
};

struct Obj_846bf0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_846bf0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194cab0;
    }
};

struct Obj_847160 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_847160() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c990;
    }
};

struct Obj_847bf0 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_847bf0() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194bb78;
    }
};

struct Obj_847fb0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_847fb0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c890;
    }
};

struct Obj_848530 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_848530() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c790;
    }
};

struct Obj_848a70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_848a70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c670;
    }
};

struct Obj_848e70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_848e70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c590;
    }
};

struct Obj_849310 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_849310() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c4d0;
    }
};

struct Obj_849870 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_849870() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194bcf0;
    }
};

struct Obj_8499d0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8499d0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c2b8;
    }
};

struct Obj_849b30 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_849b30() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c120;
    }
};

struct Obj_849c90 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_849c90() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194c020;
    }
};

struct Obj_849df0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_849df0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194bf20;
    }
};

struct MemoryCreateNiRefObject3 {
    void* Op840bc0();
    void* Op8414b0();
    void* Op841a30();
    void* Op841f70();
    void* Op8424c0();
    void* Op8428a0();
    void* Op842e10();
    void* Op843770();
    void* Op843b20();
    void* Op8440a0();
    void* Op844620();
    void* Op844b40();
    void* Op845020();
    void* Op845860();
    void* Op845d60();
    void* Op846240();
    void* Op846670();
    void* Op846bf0();
    void* Op847160();
    void* Op847bf0();
    void* Op847fb0();
    void* Op848530();
    void* Op848a70();
    void* Op848e70();
    void* Op849310();
    void* Op849870();
    void* Op8499d0();
    void* Op849b30();
    void* Op849c90();
    void* Op849df0();
};
