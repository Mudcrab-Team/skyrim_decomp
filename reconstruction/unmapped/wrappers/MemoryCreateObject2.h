// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_1937e78[1];
    extern std::uint8_t Data_1937e90[1];
    extern std::uint8_t Data_1937ea8[1];
    extern std::uint8_t Data_1937fc8[1];
    extern std::uint8_t Data_1937fe0[1];
    extern std::uint8_t Data_1938010[1];
    extern std::uint8_t Data_1938040[1];
    extern std::uint8_t Data_1938070[1];
    extern std::uint8_t Data_19380a0[1];
    extern std::uint8_t Data_19380b8[1];
    extern std::uint8_t Data_1938100[1];
    extern std::uint8_t Data_1938280[1];
    extern std::uint8_t Data_1938298[1];
    extern std::uint8_t Data_19382b0[1];
    extern std::uint8_t Data_19382c8[1];
    extern std::uint8_t Data_19382e0[1];
    extern std::uint8_t Data_19382f8[1];
    extern std::uint8_t Data_1938310[1];
    extern std::uint8_t Data_1938340[1];
    extern std::uint8_t Data_1938370[1];
    extern std::uint8_t Data_19383d0[1];
    extern std::uint8_t Data_1938418[1];
    extern std::uint8_t Data_1938508[1];
    extern std::uint8_t Data_1938520[1];
    extern std::uint8_t Data_1938568[1];
    extern std::uint8_t Data_1938580[1];
    extern std::uint8_t Data_1938598[1];
    extern std::uint8_t Data_19385b0[1];
    extern std::uint8_t Data_19385c8[1];
    extern std::uint8_t Data_19385e0[1];
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

struct Obj_7d4b40 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4b40() {
        f_8 = 0u;
        f_0 = Data_19385b0;
    }
};

struct Obj_7d4ba0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4ba0() {
        f_8 = 0u;
        f_0 = Data_1938598;
    }
};

struct Obj_7d4c00 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4c00() {
        f_8 = 0u;
        f_0 = Data_1938010;
    }
};

struct Obj_7d4c60 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4c60() {
        f_8 = 0u;
        f_0 = Data_19382b0;
    }
};

struct Obj_7d4cc0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4cc0() {
        f_8 = 0u;
        f_0 = Data_19382c8;
    }
};

struct Obj_7d4d20 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4d20() {
        f_8 = 0u;
        f_0 = Data_19382e0;
    }
};

struct Obj_7d4d80 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4d80() {
        f_8 = 0u;
        f_0 = Data_1937ea8;
    }
};

struct Obj_7d4de0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4de0() {
        f_8 = 0u;
        f_0 = Data_1937e90;
    }
};

struct Obj_7d4e40 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4e40() {
        f_8 = 0u;
        f_0 = Data_1937e78;
    }
};

struct Obj_7d4ea0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4ea0() {
        f_8 = 0u;
        f_0 = Data_1938070;
    }
};

struct Obj_7d4f00 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4f00() {
        f_8 = 0u;
        f_0 = Data_19380b8;
    }
};

struct Obj_7d4f60 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4f60() {
        f_8 = 0u;
        f_0 = Data_1938280;
    }
};

struct Obj_7d4fc0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d4fc0() {
        f_8 = 0u;
        f_0 = Data_1938298;
    }
};

struct Obj_7d5020 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5020() {
        f_8 = 0u;
        f_0 = Data_19382f8;
    }
};

struct Obj_7d5080 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5080() {
        f_8 = 0u;
        f_0 = Data_1938310;
    }
};

struct Obj_7d50e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d50e0() {
        f_8 = 0u;
        f_0 = Data_1937fc8;
    }
};

struct Obj_7d5140 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5140() {
        f_8 = 0u;
        f_0 = Data_1937fe0;
    }
};

struct Obj_7d51a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d51a0() {
        f_8 = 0u;
        f_0 = Data_19383d0;
    }
};

struct Obj_7d5200 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5200() {
        f_8 = 0u;
        f_0 = Data_1938040;
    }
};

struct Obj_7d5260 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5260() {
        f_8 = 0u;
        f_0 = Data_19380a0;
    }
};

struct Obj_7d52c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d52c0() {
        f_8 = 0u;
        f_0 = Data_1938418;
    }
};

struct Obj_7d5320 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5320() {
        f_8 = 0u;
        f_0 = Data_1938370;
    }
};

struct Obj_7d5380 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5380() {
        f_8 = 0u;
        f_0 = Data_1938100;
    }
};

struct Obj_7d53e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d53e0() {
        f_8 = 0u;
        f_0 = Data_1938580;
    }
};

struct Obj_7d5440 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5440() {
        f_8 = 0u;
        f_0 = Data_19385e0;
    }
};

struct Obj_7d54a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d54a0() {
        f_8 = 0u;
        f_0 = Data_1938568;
    }
};

struct Obj_7d5500 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5500() {
        f_8 = 0u;
        f_0 = Data_19385c8;
    }
};

struct Obj_7d5560 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5560() {
        f_8 = 0u;
        f_0 = Data_1938340;
    }
};

struct Obj_7d55c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d55c0() {
        f_8 = 0u;
        f_0 = Data_1938508;
    }
};

struct Obj_7d5620 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5620() {
        f_8 = 0u;
        f_0 = Data_1938520;
    }
};

struct MemoryCreateObject2 {
    void* Op7d4b40();
    void* Op7d4ba0();
    void* Op7d4c00();
    void* Op7d4c60();
    void* Op7d4cc0();
    void* Op7d4d20();
    void* Op7d4d80();
    void* Op7d4de0();
    void* Op7d4e40();
    void* Op7d4ea0();
    void* Op7d4f00();
    void* Op7d4f60();
    void* Op7d4fc0();
    void* Op7d5020();
    void* Op7d5080();
    void* Op7d50e0();
    void* Op7d5140();
    void* Op7d51a0();
    void* Op7d5200();
    void* Op7d5260();
    void* Op7d52c0();
    void* Op7d5320();
    void* Op7d5380();
    void* Op7d53e0();
    void* Op7d5440();
    void* Op7d54a0();
    void* Op7d5500();
    void* Op7d5560();
    void* Op7d55c0();
    void* Op7d5620();
};
