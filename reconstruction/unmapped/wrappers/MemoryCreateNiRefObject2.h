// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateNiRefObject2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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
    extern std::uint8_t Data_194a400[1];
    extern std::uint8_t Data_194a4c0[1];
    extern std::uint8_t Data_194b2a8[1];
    extern std::uint8_t Data_194b420[1];
    extern std::uint8_t Data_194b558[1];
    extern std::uint8_t Data_194dab8[1];
    extern std::uint8_t Data_194dbd8[1];
    extern std::uint8_t Data_194dcd8[1];
    extern std::uint8_t Data_194ddd8[1];
    extern std::uint8_t Data_194df78[1];
    extern std::uint8_t Data_194e038[1];
    extern std::uint8_t Data_194e138[1];
    extern std::uint8_t Data_194e238[1];
    extern std::uint8_t Data_194e338[1];
    extern std::uint8_t Data_194e458[1];
    extern std::uint8_t Data_194e558[1];
    extern std::uint8_t Data_194e658[1];
    extern std::uint8_t Data_194e778[1];
    extern std::uint8_t Data_194e858[1];
    extern std::uint8_t Data_194e978[1];
    extern std::uint8_t Data_194ea98[1];
    extern std::uint8_t Data_194ec38[1];
    extern std::uint8_t Data_194ecf8[1];
    extern std::uint8_t Data_194edb8[1];
    extern std::uint8_t Data_194eef8[1];
    extern std::uint8_t Data_194efd8[1];
    extern std::uint8_t Data_194f0f8[1];
    extern std::uint8_t Data_194f1f8[1];
    extern std::uint8_t Data_194f2f8[1];
    extern std::uint8_t Data_194f418[1];
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

struct Obj_832180 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_832180() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a4c0;
    }
};

struct Obj_8322e0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8322e0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f418;
    }
};

struct Obj_832440 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_832440() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a400;
    }
};

struct Obj_832820 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_832820() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f2f8;
    }
};

struct Obj_8329c0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8329c0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f1f8;
    }
};

struct Obj_838890 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_838890() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f0f8;
    }
};

struct Obj_838f30 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_838f30() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194efd8;
    }
};

struct Obj_83b110 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83b110() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194eef8;
    }
};

struct Obj_83b450 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83b450() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194edb8;
    }
};

struct Obj_83b5b0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83b5b0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ecf8;
    }
};

struct Obj_83b710 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83b710() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ec38;
    }
};

struct Obj_83b870 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83b870() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ea98;
    }
};

struct Obj_83ba70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83ba70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e978;
    }
};

struct Obj_83bc90 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_83bc90() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194b2a8;
    }
};

struct Obj_83be70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83be70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e858;
    }
};

struct Obj_83bfd0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83bfd0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e778;
    }
};

struct Obj_83c130 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83c130() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e658;
    }
};

struct Obj_83c290 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83c290() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e558;
    }
};

struct Obj_83c3f0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83c3f0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e458;
    }
};

struct Obj_83cb00 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_83cb00() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194b420;
    }
};

struct Obj_83cf30 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83cf30() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e338;
    }
};

struct Obj_83d470 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83d470() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e238;
    }
};

struct Obj_83d9f0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83d9f0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e138;
    }
};

struct Obj_83dfc0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83dfc0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194e038;
    }
};

struct Obj_83e400 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83e400() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194df78;
    }
};

struct Obj_83ef30 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_83ef30() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194b558;
    }
};

struct Obj_83f550 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83f550() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ddd8;
    }
};

struct Obj_83fa80 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_83fa80() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194dcd8;
    }
};

struct Obj_840020 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_840020() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194dbd8;
    }
};

struct Obj_840640 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_840640() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194dab8;
    }
};

struct MemoryCreateNiRefObject2 {
    void* Op832180();
    void* Op8322e0();
    void* Op832440();
    void* Op832820();
    void* Op8329c0();
    void* Op838890();
    void* Op838f30();
    void* Op83b110();
    void* Op83b450();
    void* Op83b5b0();
    void* Op83b710();
    void* Op83b870();
    void* Op83ba70();
    void* Op83bc90();
    void* Op83be70();
    void* Op83bfd0();
    void* Op83c130();
    void* Op83c290();
    void* Op83c3f0();
    void* Op83cb00();
    void* Op83cf30();
    void* Op83d470();
    void* Op83d9f0();
    void* Op83dfc0();
    void* Op83e400();
    void* Op83ef30();
    void* Op83f550();
    void* Op83fa80();
    void* Op840020();
    void* Op840640();
};
