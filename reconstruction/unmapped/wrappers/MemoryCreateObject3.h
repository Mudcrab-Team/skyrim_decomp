// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// MemoryCreateObject3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
    extern std::uint8_t Data_1937ed8[1];
    extern std::uint8_t Data_1937f20[1];
    extern std::uint8_t Data_1937ff8[1];
    extern std::uint8_t Data_19380e8[1];
    extern std::uint8_t Data_1938118[1];
    extern std::uint8_t Data_1938130[1];
    extern std::uint8_t Data_1938148[1];
    extern std::uint8_t Data_1938160[1];
    extern std::uint8_t Data_1938178[1];
    extern std::uint8_t Data_1938190[1];
    extern std::uint8_t Data_19381a8[1];
    extern std::uint8_t Data_19381c0[1];
    extern std::uint8_t Data_19381d8[1];
    extern std::uint8_t Data_19381f0[1];
    extern std::uint8_t Data_1938208[1];
    extern std::uint8_t Data_1938220[1];
    extern std::uint8_t Data_1938238[1];
    extern std::uint8_t Data_1938250[1];
    extern std::uint8_t Data_1938268[1];
    extern std::uint8_t Data_1938328[1];
    extern std::uint8_t Data_19383e8[1];
    extern std::uint8_t Data_1938400[1];
    extern std::uint8_t Data_1938448[1];
    extern std::uint8_t Data_19384c0[1];
    extern std::uint8_t Data_19384d8[1];
    extern std::uint8_t Data_19384f0[1];
    extern std::uint8_t Data_19385f8[1];
    extern std::uint8_t Data_1938610[1];
    extern std::uint8_t Data_1938628[1];
    extern std::uint8_t Data_19386b8[1];
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

struct Obj_7d5680 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5680() {
        f_8 = 0u;
        f_0 = Data_1938220;
    }
};

struct Obj_7d56e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d56e0() {
        f_8 = 0u;
        f_0 = Data_1938208;
    }
};

struct Obj_7d5740 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5740() {
        f_8 = 0u;
        f_0 = Data_1938238;
    }
};

struct Obj_7d57a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d57a0() {
        f_8 = 0u;
        f_0 = Data_19381f0;
    }
};

struct Obj_7d5800 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5800() {
        f_8 = 0u;
        f_0 = Data_1938250;
    }
};

struct Obj_7d5860 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5860() {
        f_8 = 0u;
        f_0 = Data_1938268;
    }
};

struct Obj_7d58c0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d58c0() {
        f_8 = 0u;
        f_0 = Data_1938160;
    }
};

struct Obj_7d5920 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5920() {
        f_8 = 0u;
        f_0 = Data_1938178;
    }
};

struct Obj_7d5980 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5980() {
        f_8 = 0u;
        f_0 = Data_19381d8;
    }
};

struct Obj_7d59e0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d59e0() {
        f_8 = 0u;
        f_0 = Data_19381c0;
    }
};

struct Obj_7d5a40 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5a40() {
        f_8 = 0u;
        f_0 = Data_1938190;
    }
};

struct Obj_7d5aa0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5aa0() {
        f_8 = 0u;
        f_0 = Data_19381a8;
    }
};

struct Obj_7d5b00 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5b00() {
        f_8 = 0u;
        f_0 = Data_1938148;
    }
};

struct Obj_7d5b60 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5b60() {
        f_8 = 0u;
        f_0 = Data_19384d8;
    }
};

struct Obj_7d5bc0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5bc0() {
        f_8 = 0u;
        f_0 = Data_19384c0;
    }
};

struct Obj_7d5c20 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5c20() {
        f_8 = 0u;
        f_0 = Data_1938130;
    }
};

struct Obj_7d5c80 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5c80() {
        f_8 = 0u;
        f_0 = Data_1938118;
    }
};

struct Obj_7d5ce0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5ce0() {
        f_8 = 0u;
        f_0 = Data_1937ff8;
    }
};

struct Obj_7d5d40 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5d40() {
        f_8 = 0u;
        f_0 = Data_1938610;
    }
};

struct Obj_7d5da0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5da0() {
        f_8 = 0u;
        f_0 = Data_1938628;
    }
};

struct Obj_7d5e00 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5e00() {
        f_8 = 0u;
        f_0 = Data_1938328;
    }
};

struct Obj_7d5e60 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5e60() {
        f_8 = 0u;
        f_0 = Data_19385f8;
    }
};

struct Obj_7d5ec0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5ec0() {
        f_8 = 0u;
        f_0 = Data_19380e8;
    }
};

struct Obj_7d5f20 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5f20() {
        f_8 = 0u;
        f_0 = Data_1938400;
    }
};

struct Obj_7d5f80 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5f80() {
        f_8 = 0u;
        f_0 = Data_19383e8;
    }
};

struct Obj_7d5fe0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d5fe0() {
        f_8 = 0u;
        f_0 = Data_1937f20;
    }
};

struct Obj_7d6040 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6040() {
        f_8 = 0u;
        f_0 = Data_1937ed8;
    }
};

struct Obj_7d60a0 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d60a0() {
        f_8 = 0u;
        f_0 = Data_19386b8;
    }
};

struct Obj_7d6100 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6100() {
        f_8 = 0u;
        f_0 = Data_1938448;
    }
};

struct Obj_7d6160 : HeapAllocBase {
    void* f_0;
    std::uint32_t f_8;
    std::uint8_t unk_c[0x4];
    Obj_7d6160() {
        f_8 = 0u;
        f_0 = Data_19384f0;
    }
};

struct MemoryCreateObject3 {
    void* Op7d5680();
    void* Op7d56e0();
    void* Op7d5740();
    void* Op7d57a0();
    void* Op7d5800();
    void* Op7d5860();
    void* Op7d58c0();
    void* Op7d5920();
    void* Op7d5980();
    void* Op7d59e0();
    void* Op7d5a40();
    void* Op7d5aa0();
    void* Op7d5b00();
    void* Op7d5b60();
    void* Op7d5bc0();
    void* Op7d5c20();
    void* Op7d5c80();
    void* Op7d5ce0();
    void* Op7d5d40();
    void* Op7d5da0();
    void* Op7d5e00();
    void* Op7d5e60();
    void* Op7d5ec0();
    void* Op7d5f20();
    void* Op7d5f80();
    void* Op7d5fe0();
    void* Op7d6040();
    void* Op7d60a0();
    void* Op7d6100();
    void* Op7d6160();
};
