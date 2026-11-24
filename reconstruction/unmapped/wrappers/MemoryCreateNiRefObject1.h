// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateNiRefObject1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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
    extern std::uint8_t Data_1943e88[1];
    extern std::uint8_t Data_1943ee8[1];
    extern std::uint8_t Data_1943fa8[1];
    extern std::uint8_t Data_19475c8[1];
    extern std::uint8_t Data_1947678[1];
    extern std::uint8_t Data_1947728[1];
    extern std::uint8_t Data_19477d8[1];
    extern std::uint8_t Data_1947888[1];
    extern std::uint8_t Data_194a5a0[1];
    extern std::uint8_t Data_194a6a0[1];
    extern std::uint8_t Data_194a7a0[1];
    extern std::uint8_t Data_194a8c0[1];
    extern std::uint8_t Data_194a9c0[1];
    extern std::uint8_t Data_194aac0[1];
    extern std::uint8_t Data_194abe0[1];
    extern std::uint8_t Data_194ad38[1];
    extern std::uint8_t Data_194aef0[1];
    extern std::uint8_t Data_194aff0[1];
    extern std::uint8_t Data_194b168[1];
    extern std::uint8_t Data_194b360[1];
    extern std::uint8_t Data_194b498[1];
    extern std::uint8_t Data_194b630[1];
    extern std::uint8_t Data_194b788[1];
    extern std::uint8_t Data_194b920[1];
    extern std::uint8_t Data_194c200[1];
    extern std::uint8_t Data_194c398[1];
    extern std::uint8_t Data_194f518[1];
    extern std::uint8_t Data_194f638[1];
    extern std::uint8_t Data_194f718[1];
    extern std::uint8_t Data_194f838[1];
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

struct Obj_8098e0 : NiRefBase {
    std::uint8_t unk_10[0x8];
    std::uint64_t f_18;
    std::uint32_t f_20;
    std::uint8_t unk_24[0xc];
    std::uint32_t f_30;
    std::uint8_t unk_34[0xc];
    std::uint64_t f_40;
    std::uint8_t unk_48[0x8];
    Obj_8098e0() : NiRefBase() {
        f_18 = 0u;
        f_20 = 0u;
        f_30 = 0u;
        f_40 = 0u;
        vftable = Data_1943e88;
    }
};

struct Obj_809a40 : NiRefBase {
    std::uint8_t unk_10[0x8];
    std::uint64_t f_18;
    std::uint32_t f_20;
    std::uint8_t unk_24[0xc];
    std::uint32_t f_30;
    std::uint8_t unk_34[0xc];
    std::uint64_t f_40;
    std::uint8_t unk_48[0x10];
    Obj_809a40() : NiRefBase() {
        f_18 = 0u;
        f_20 = 0u;
        f_30 = 0u;
        f_40 = 0u;
        vftable = Data_1943ee8;
    }
};

struct Obj_809d60 : NiRefBase {
    std::uint8_t unk_10[0x8];
    std::uint64_t f_18;
    std::uint32_t f_20;
    std::uint8_t unk_24[0xc];
    std::uint32_t f_30;
    std::uint8_t unk_34[0xc];
    std::uint64_t f_40;
    Obj_809d60() : NiRefBase() {
        f_18 = 0u;
        f_20 = 0u;
        f_30 = 0u;
        f_40 = 0u;
        vftable = Data_1943fa8;
    }
};

struct Obj_82f360 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0xc];
    Obj_82f360() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_19475c8;
    }
};

struct Obj_82f4c0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x14];
    Obj_82f4c0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_1947678;
    }
};

struct Obj_82f620 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0xc];
    Obj_82f620() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_1947728;
    }
};

struct Obj_82f780 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0xc];
    Obj_82f780() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_19477d8;
    }
};

struct Obj_82f8e0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0xc];
    Obj_82f8e0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_1947888;
    }
};

struct Obj_82fdf0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_82fdf0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b920;
    }
};

struct Obj_82ff50 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_82ff50() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b788;
    }
};

struct Obj_8300b0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8300b0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b630;
    }
};

struct Obj_830430 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830430() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b498;
    }
};

struct Obj_830590 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830590() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b360;
    }
};

struct Obj_830730 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830730() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194b168;
    }
};

struct Obj_830890 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830890() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194aff0;
    }
};

struct Obj_8309f0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8309f0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194aef0;
    }
};

struct Obj_830bd0 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_830bd0() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194c200;
    }
};

struct Obj_830d70 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830d70() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ad38;
    }
};

struct Obj_830ed0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_830ed0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194abe0;
    }
};

struct Obj_831070 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831070() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194aac0;
    }
};

struct Obj_8311d0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_8311d0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a9c0;
    }
};

struct Obj_831330 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831330() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a8c0;
    }
};

struct Obj_831610 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_831610() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194c398;
    }
};

struct Obj_831770 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831770() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f838;
    }
};

struct Obj_831900 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831900() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a7a0;
    }
};

struct Obj_831a60 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831a60() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f718;
    }
};

struct Obj_831bc0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831bc0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a6a0;
    }
};

struct Obj_831d20 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831d20() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f638;
    }
};

struct Obj_831ea0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_831ea0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194a5a0;
    }
};

struct Obj_832020 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_832020() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194f518;
    }
};

struct MemoryCreateNiRefObject1 {
    void* Op8098e0();
    void* Op809a40();
    void* Op809d60();
    void* Op82f360();
    void* Op82f4c0();
    void* Op82f620();
    void* Op82f780();
    void* Op82f8e0();
    void* Op82fdf0();
    void* Op82ff50();
    void* Op8300b0();
    void* Op830430();
    void* Op830590();
    void* Op830730();
    void* Op830890();
    void* Op8309f0();
    void* Op830bd0();
    void* Op830d70();
    void* Op830ed0();
    void* Op831070();
    void* Op8311d0();
    void* Op831330();
    void* Op831610();
    void* Op831770();
    void* Op831900();
    void* Op831a60();
    void* Op831bc0();
    void* Op831d20();
    void* Op831ea0();
    void* Op832020();
};
