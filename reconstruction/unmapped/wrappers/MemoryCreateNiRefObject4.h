// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateNiRefObject4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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
    extern std::uint8_t Data_194ba98[1];
    extern std::uint8_t Data_194bc30[1];
    extern std::uint8_t Data_194bda8[1];
    extern std::uint8_t Data_194be88[1];
    extern std::uint8_t Data_1955990[1];
    extern std::uint8_t Data_195e308[1];
    extern std::uint8_t Data_1964d68[1];
    extern std::uint8_t Data_1966748[1];
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

struct Obj_849f50 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_849f50() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194bda8;
    }
};

struct Obj_84a0f0 : NiRefBase {
    std::uint64_t f_10;
    std::uint8_t unk_18[0x8];
    Obj_84a0f0() : NiRefBase() {
        f_10 = 0u;
        vftable = Data_194be88;
    }
};

struct Obj_84a290 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_84a290() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194bc30;
    }
};

struct Obj_84a3f0 : NiRefBase {
    std::uint8_t unk_10[0x10];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x24];
    Obj_84a3f0() : NiRefBase() {
        f_20 = 0u;
        f_28 = 0u;
        vftable = Data_194ba98;
    }
};

struct Obj_862df0 : NiRefBase {
    std::uint8_t unk_10[0x8];
    std::uint32_t f_18;
    std::uint8_t unk_1c[0xc];
    Obj_862df0() : NiRefBase() {
        f_18 = 0u;
        vftable = Data_1955990;
    }
};

struct Obj_8a2480 : NiRefBase {
    std::uint32_t f_10;
    std::uint8_t unk_14[0xc];
    std::uint64_t f_20;
    std::uint64_t f_28;
    std::uint64_t f_30;
    std::uint64_t f_38;
    std::uint64_t f_40;
    std::uint64_t f_48;
    std::uint16_t f_50;
    std::uint8_t unk_52[0x1];
    std::uint8_t f_53;
    std::uint8_t unk_54[0xc];
    Obj_8a2480() : NiRefBase() {
        f_10 = 0u;
        f_30 = 0u;
        f_38 = 0u;
        f_20 = 0u;
        f_40 = 0u;
        f_28 = 0u;
        f_48 = 0u;
        f_50 = 0u;
        f_53 = 0u;
        vftable = Data_195e308;
    }
};

struct Obj_8cc380 : NiRefBase {
    std::uint32_t f_10;
    std::uint8_t unk_14[0xc];
    std::uint64_t f_20;
    std::uint64_t f_28;
    std::uint64_t f_30;
    std::uint64_t f_38;
    std::uint32_t f_40;
    std::uint8_t unk_44[0x4];
    std::uint64_t f_48;
    std::uint64_t f_50;
    std::uint32_t f_58;
    std::uint8_t unk_5c[0x4];
    std::uint64_t f_60;
    std::uint8_t unk_68[0x8];
    std::uint64_t f_70;
    std::uint16_t f_78;
    std::uint8_t unk_7a[0x1];
    std::uint8_t f_7b;
    std::uint8_t unk_7c[0xc];
    Obj_8cc380() : NiRefBase() {
        f_10 = 0u;
        f_20 = 0u;
        f_30 = 0u;
        f_28 = 0u;
        f_38 = 0u;
        f_40 = 0u;
        f_48 = 0u;
        f_60 = 0u;
        f_50 = 0u;
        f_58 = 0u;
        f_70 = 0u;
        f_78 = 0u;
        f_7b = 0u;
        vftable = Data_1964d68;
    }
};

struct Obj_8d5330 : NiRefBase {
    std::uint32_t f_10;
    std::uint8_t unk_14[0xc];
    std::uint64_t f_20;
    std::uint64_t f_28;
    std::uint64_t f_30;
    std::uint64_t f_38;
    std::uint64_t f_40;
    std::uint64_t f_48;
    std::uint16_t f_50;
    std::uint8_t unk_52[0x1];
    std::uint8_t f_53;
    std::uint8_t unk_54[0xc];
    Obj_8d5330() : NiRefBase() {
        f_10 = 0u;
        f_30 = 0u;
        f_38 = 0u;
        f_20 = 0u;
        f_40 = 0u;
        f_28 = 0u;
        f_48 = 0u;
        f_50 = 0u;
        f_53 = 0u;
        vftable = Data_1966748;
    }
};

struct MemoryCreateNiRefObject4 {
    void* Op849f50();
    void* Op84a0f0();
    void* Op84a290();
    void* Op84a3f0();
    void* Op862df0();
    void* Op8a2480();
    void* Op8cc380();
    void* Op8d5330();
};
