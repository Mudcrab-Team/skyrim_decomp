// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_1937e48[1];
    extern std::uint8_t Data_1937e60[1];
    extern std::uint8_t Data_1937ec0[1];
    extern std::uint8_t Data_1937ef0[1];
    extern std::uint8_t Data_1937f08[1];
    extern std::uint8_t Data_1937f38[1];
    extern std::uint8_t Data_1937f50[1];
    extern std::uint8_t Data_1937f68[1];
    extern std::uint8_t Data_1937f80[1];
    extern std::uint8_t Data_1937f98[1];
    extern std::uint8_t Data_1937fb0[1];
    extern std::uint8_t Data_1938028[1];
    extern std::uint8_t Data_1938058[1];
    extern std::uint8_t Data_1938088[1];
    extern std::uint8_t Data_19380d0[1];
    extern std::uint8_t Data_1938358[1];
    extern std::uint8_t Data_19383a0[1];
    extern std::uint8_t Data_19383b8[1];
    extern std::uint8_t Data_1938490[1];
    extern std::uint8_t Data_19384a8[1];
    extern std::uint8_t Data_1938538[1];
    extern std::uint8_t Data_1938550[1];
    extern std::uint8_t Data_1938688[1];
    extern std::uint8_t Data_19386a0[1];
    extern std::uint8_t Data_19386d0[1];
    extern std::uint8_t Data_19386e8[1];
    extern std::uint8_t Data_1984818[1];
    extern std::uint8_t Data_1984968[1];
    extern std::uint8_t Data_1984988[1];
    extern std::uint8_t Data_1984998[1];
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

struct Obj_7d61c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d61c0() {
        f_8 = 0u;
        f_0 = Data_1938538;
    }
};

struct Obj_7d6220 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6220() {
        f_8 = 0u;
        f_0 = Data_1938550;
    }
};

struct Obj_7d6280 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6280() {
        f_8 = 0u;
        f_0 = Data_19383b8;
    }
};

struct Obj_7d62e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d62e0() {
        f_8 = 0u;
        f_0 = Data_1938358;
    }
};

struct Obj_7d6340 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6340() {
        f_8 = 0u;
        f_0 = Data_19386a0;
    }
};

struct Obj_7d63a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d63a0() {
        f_8 = 0u;
        f_0 = Data_1938688;
    }
};

struct Obj_7d6400 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6400() {
        f_8 = 0u;
        f_0 = Data_1938088;
    }
};

struct Obj_7d6460 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6460() {
        f_8 = 0u;
        f_0 = Data_1938058;
    }
};

struct Obj_7d64c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d64c0() {
        f_8 = 0u;
        f_0 = Data_19380d0;
    }
};

struct Obj_7d6520 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6520() {
        f_8 = 0u;
        f_0 = Data_19384a8;
    }
};

struct Obj_7d6580 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6580() {
        f_8 = 0u;
        f_0 = Data_1937ec0;
    }
};

struct Obj_7d65e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d65e0() {
        f_8 = 0u;
        f_0 = Data_1938490;
    }
};

struct Obj_7d6640 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6640() {
        f_8 = 0u;
        f_0 = Data_1937f38;
    }
};

struct Obj_7d66a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d66a0() {
        f_8 = 0u;
        f_0 = Data_1937ef0;
    }
};

struct Obj_7d6700 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6700() {
        f_8 = 0u;
        f_0 = Data_1937f98;
    }
};

struct Obj_7d6760 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6760() {
        f_8 = 0u;
        f_0 = Data_1937fb0;
    }
};

struct Obj_7d67c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d67c0() {
        f_8 = 0u;
        f_0 = Data_1938028;
    }
};

struct Obj_7d6820 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6820() {
        f_8 = 0u;
        f_0 = Data_19383a0;
    }
};

struct Obj_7d6880 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6880() {
        f_8 = 0u;
        f_0 = Data_19386e8;
    }
};

struct Obj_7d68e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d68e0() {
        f_8 = 0u;
        f_0 = Data_1937f50;
    }
};

struct Obj_7d6940 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6940() {
        f_8 = 0u;
        f_0 = Data_1937f08;
    }
};

struct Obj_7d69a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d69a0() {
        f_8 = 0u;
        f_0 = Data_1937f68;
    }
};

struct Obj_7d6a00 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6a00() {
        f_8 = 0u;
        f_0 = Data_1937f80;
    }
};

struct Obj_7d6a60 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6a60() {
        f_8 = 0u;
        f_0 = Data_1937e60;
    }
};

struct Obj_7d6ac0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6ac0() {
        f_8 = 0u;
        f_0 = Data_1937e48;
    }
};

struct Obj_7d6b20 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6b20() {
        f_8 = 0u;
        f_0 = Data_19386d0;
    }
};

struct Obj_98ccf0 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x6];
    std::uint64_t f_10;
    std::uint32_t f_18;
    std::uint8_t unk_1c[0x4];
    std::uint64_t f_20;
    std::uint32_t f_28;
    std::uint8_t unk_2c[0x4];
    Obj_98ccf0() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1984818;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
        f_28 = 0x4u;
    }
};

struct Obj_98cfa0 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x6];
    std::uint64_t f_10;
    std::uint8_t f_18;
    std::uint8_t unk_19[0x3];
    std::uint32_t f_1c;
    std::uint32_t f_20;
    std::uint32_t f_24;
    Obj_98cfa0() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1984968;
        f_10 = 0u;
        f_18 = 0x3u;
        f_1c = 0u;
        f_20 = 0x3f800000u;
        f_24 = 0x101u;
    }
};

struct Obj_98d1f0 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0x6];
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    Obj_98d1f0() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1984988;
        f_10 = 0u;
    }
};

struct Obj_98d310 : HeapAllocBase {
    void* f_0;
    std::uint8_t f_8;
    std::uint8_t f_9;
    std::uint8_t unk_a[0xe];
    Obj_98d310() {
        f_8 = 0u;
        f_9 = 0u;
        f_0 = Data_1984998;
    }
};

struct MemoryCreateObject4 {
    void* Op7d61c0();
    void* Op7d6220();
    void* Op7d6280();
    void* Op7d62e0();
    void* Op7d6340();
    void* Op7d63a0();
    void* Op7d6400();
    void* Op7d6460();
    void* Op7d64c0();
    void* Op7d6520();
    void* Op7d6580();
    void* Op7d65e0();
    void* Op7d6640();
    void* Op7d66a0();
    void* Op7d6700();
    void* Op7d6760();
    void* Op7d67c0();
    void* Op7d6820();
    void* Op7d6880();
    void* Op7d68e0();
    void* Op7d6940();
    void* Op7d69a0();
    void* Op7d6a00();
    void* Op7d6a60();
    void* Op7d6ac0();
    void* Op7d6b20();
    void* Op98ccf0();
    void* Op98cfa0();
    void* Op98d1f0();
    void* Op98d310();
};
