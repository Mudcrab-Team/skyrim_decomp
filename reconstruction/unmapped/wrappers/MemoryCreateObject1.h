// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_18c4770[1];
    extern std::uint8_t Data_18c48d0[1];
    extern std::uint8_t Data_18c4a38[1];
    extern std::uint8_t Data_18c6a40[1];
    extern std::uint8_t Data_18c6d98[1];
    extern std::uint8_t Data_18c6f78[1];
    extern std::uint8_t Data_18c7470[1];
    extern std::uint8_t Data_18c7510[1];
    extern std::uint8_t Data_18c75b0[1];
    extern std::uint8_t Data_18c7650[1];
    extern std::uint8_t Data_18c76f0[1];
    extern std::uint8_t Data_18c7790[1];
    extern std::uint8_t Data_18c7830[1];
    extern std::uint8_t Data_1938388[1];
    extern std::uint8_t Data_1938430[1];
    extern std::uint8_t Data_1938460[1];
    extern std::uint8_t Data_1938478[1];
    extern std::uint8_t Data_1938640[1];
    extern std::uint8_t Data_1938658[1];
    extern std::uint8_t Data_1938670[1];
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

struct Obj_1d0f50 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_1d6ab0 : HeapAllocBase {
    std::uint8_t unk_0[0x8];
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_1d6ab0() {
        f_8 = 0u;
    }
};

struct Obj_2d4840 : HeapAllocBase {
    std::uint8_t unk_0[0x10];
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_2d4840() {
        f_10 = 0u;
    }
};

struct Obj_2d48a0 : HeapAllocBase {
    std::uint8_t unk_0[0x10];
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_2d48a0() {
        f_10 = 0u;
    }
};

struct Obj_2d4900 : HeapAllocBase {
    std::uint8_t unk_0[0x8];
    std::uint32_t f_8;
    std::uint8_t unk_c[0xc];
    Obj_2d4900() {
        f_8 = 0u;
    }
};

struct Obj_2d4960 : HeapAllocBase {
    std::uint8_t unk_0[0x8];
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    std::uint64_t f_10;
    Obj_2d4960() {
        f_8 = 0u;
        f_10 = 0u;
    }
};

struct Obj_2dcb90 : HeapAllocBase {
    std::uint8_t unk_0[0x10];
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    std::uint8_t f_28;
    std::uint8_t unk_29[0x7];
    Obj_2dcb90() {
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
        f_28 = 0x1u;
    }
};

struct Obj_2fa450 : HeapAllocBase {
    std::uint8_t unk_0[0x8];
    std::uint64_t f_8;
    Obj_2fa450() {
        f_8 = 0u;
    }
};

struct Obj_3149c0 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_44fd40 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_44fd40() {
        f_8 = 0u;
        f_0 = Data_18c48d0;
        f_10 = 0u;
    }
};

struct Obj_44fe60 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_44fe60() {
        f_8 = 0u;
        f_0 = Data_18c4a38;
        f_10 = 0u;
    }
};

struct Obj_44ff80 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    Obj_44ff80() {
        f_8 = 0u;
        f_0 = Data_18c4770;
    }
};

struct Obj_459850 : HeapAllocBase {
    void* f_0;
    Obj_459850() {
        f_0 = Data_18c6a40;
    }
};

struct Obj_4598b0 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t f_14;
    std::uint8_t f_15;
    std::uint8_t unk_16[0x2];
    Obj_4598b0() {
        f_8 = 0u;
        f_0 = Data_18c7470;
        f_10 = 0u;
        f_14 = 0u;
        f_15 = 0x1u;
    }
};

struct Obj_459980 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t f_14;
    std::uint8_t unk_15[0x3];
    Obj_459980() {
        f_8 = 0u;
        f_0 = Data_18c7510;
        f_10 = 0u;
        f_14 = 0u;
    }
};

struct Obj_459b10 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
    Obj_459b10() {
        f_8 = 0u;
        f_0 = Data_18c75b0;
        f_10 = 0u;
    }
};

struct Obj_459b80 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    Obj_459b80() {
        f_8 = 0u;
        f_0 = Data_18c7650;
    }
};

struct Obj_459c40 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
    Obj_459c40() {
        f_8 = 0u;
        f_0 = Data_18c76f0;
        f_10 = 0u;
    }
};

struct Obj_459e30 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t unk_9[0x7];
    Obj_459e30() {
        f_8 = 0u;
        f_0 = Data_18c7790;
    }
};

struct Obj_45a1f0 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_45a1f0() {
        f_8 = 0u;
        f_0 = Data_18c6d98;
        f_10 = 0u;
    }
};

struct Obj_45a400 : HeapAllocBase {
    void* f_0;
    std::uint64_t f_8;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_45a400() {
        f_8 = 0u;
        f_0 = Data_18c6f78;
        f_10 = 0u;
    }
};

struct Obj_45a590 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_45a590() {
        f_8 = 0xbf800000u;
        f_0 = Data_18c7830;
    }
};

struct Obj_52f870 {
    std::uint64_t f_0;
    std::uint64_t f_8;
    std::uint64_t f_10;
};

struct Obj_7d48a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d48a0() {
        f_8 = 0u;
        f_0 = Data_1938388;
    }
};

struct Obj_7d4900 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4900() {
        f_8 = 0u;
        f_0 = Data_1938430;
    }
};

struct Obj_7d4960 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4960() {
        f_8 = 0u;
        f_0 = Data_1938478;
    }
};

struct Obj_7d49c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d49c0() {
        f_8 = 0u;
        f_0 = Data_1938658;
    }
};

struct Obj_7d4a20 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4a20() {
        f_8 = 0u;
        f_0 = Data_1938670;
    }
};

struct Obj_7d4a80 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4a80() {
        f_8 = 0u;
        f_0 = Data_1938640;
    }
};

struct Obj_7d4ae0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4ae0() {
        f_8 = 0u;
        f_0 = Data_1938460;
    }
};

struct MemoryCreateObject1 {
    static void* Op1d0f50();
    void* Op1d6ab0();
    void* Op2d4840();
    void* Op2d48a0();
    void* Op2d4900();
    void* Op2d4960();
    void* Op2dcb90();
    void* Op2fa450();
    static void* Op3149c0();
    void* Op44fd40();
    void* Op44fe60();
    void* Op44ff80();
    void* Op459850();
    void* Op4598b0();
    void* Op459980();
    void* Op459b10();
    void* Op459b80();
    void* Op459c40();
    void* Op459e30();
    void* Op45a1f0();
    void* Op45a400();
    void* Op45a590();
    static void* Op52f870();
    void* Op7d48a0();
    void* Op7d4900();
    void* Op7d4960();
    void* Op7d49c0();
    void* Op7d4a20();
    void* Op7d4a80();
    void* Op7d4ae0();
};
