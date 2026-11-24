// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda MemoryFactoryManager::Allocate factory helpers.
// BSTSmartPointerCreate, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original signatures unknown.
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
    extern std::uint8_t Data_1860ce0[1];
    extern std::uint8_t Data_1863be8[1];
    extern std::uint8_t Data_19937b8[1];
    extern std::uint8_t Data_1993c58[1];
    extern std::uint8_t Data_1993cb8[1];
    extern std::uint8_t Data_199e7f8[1];
    extern std::uint8_t Data_19a29e0[1];
    extern std::uint8_t Data_19a2ec0[1];
    extern std::uint8_t Data_19a3be0[1];
    extern std::uint8_t Data_19a7f48[1];
    extern std::uint8_t Data_19a7fa8[1];
    extern std::uint8_t Data_19a8008[1];
    extern std::uint8_t Data_19a8068[1];
    extern std::uint8_t Data_19a80c8[1];
    extern std::uint8_t Data_19a8128[1];
    extern std::uint8_t Data_19a8188[1];
    extern std::uint8_t Data_19a81e8[1];
    extern std::uint8_t Data_19a8248[1];
    extern std::uint8_t Data_19a82a8[1];
    extern std::uint8_t Data_19a8308[1];
    extern std::uint8_t Data_19a8368[1];
    extern std::uint8_t Data_19a83c8[1];
    extern std::uint8_t Data_19a8428[1];
    extern std::uint8_t Data_19a8488[1];
    extern std::uint8_t Data_19a84e8[1];
    extern std::uint8_t Data_19a8e90[1];
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

template <class T>
struct MemoryFactorySmartPtr {
    T* ptr;
    explicit MemoryFactorySmartPtr(T* p) throw() : ptr(p) {
        if (ptr) {
            ptr->IncRef();
        }
    }
    ~MemoryFactorySmartPtr() throw() {
        if (ptr && ptr->DecRef() == 0u) {
            ptr->Destroy();
        }
    }
    MemoryFactorySmartPtr& operator=(const MemoryFactorySmartPtr& rhs) throw() {
        T* old = ptr;
        if (rhs.ptr != old) {
            if (rhs.ptr) {
                rhs.ptr->IncRef();
            }
            ptr = rhs.ptr;
            if (old && old->DecRef() == 0u) {
                old->Destroy();
            }
        }
        return *this;
    }
};

struct Obj_3e13b0 : HeapAllocBase {
    void* vftable;
    std::uint32_t refCount;
    std::uint8_t unk_c[0xc];
    Obj_3e13b0() {
        refCount = 0u;
        vftable = Data_1860ce0;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_3f0e80 : HeapAllocBase {
    void* vftable;
    std::uint32_t refCount;
    std::uint8_t unk_c[0x4];
    Obj_3f0e80() {
        refCount = 0u;
        vftable = Data_1863be8;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a09090 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    std::uint64_t f_20;
    Obj_a09090() {
        refCount = 0u;
        vftable = Data_19937b8;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a09260 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    Obj_a09260() {
        refCount = 0u;
        vftable = Data_1993c58;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a09420 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    Obj_a09420() {
        refCount = 0u;
        vftable = Data_1993cb8;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a28dc0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    std::uint64_t f_28;
    std::uint64_t f_30;
    std::uint64_t f_38;
    std::uint64_t f_40;
    std::uint8_t f_48;
    std::uint8_t unk_49[0x7];
    Obj_a28dc0() {
        refCount = 0u;
        vftable = Data_199e7f8;
        f_28 = 0u;
        f_10 = 0u;
        f_18 = 0u;
        f_30 = 0u;
        f_20 = 0u;
        f_38 = 0u;
        f_40 = 0u;
        f_48 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a321c0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    Obj_a321c0() {
        refCount = 0u;
        vftable = Data_19a29e0;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a33690 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint32_t f_20;
    std::uint8_t unk_24[0x4];
    std::uint64_t f_28;
    Obj_a33690() {
        refCount = 0u;
        vftable = Data_19a2ec0;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
        f_28 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a35f40 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t f_14;
    std::uint8_t unk_15[0x3];
    std::uint64_t f_18;
    Obj_a35f40() {
        refCount = 0u;
        vftable = Data_19a3be0;
        f_10 = 0u;
        f_14 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a4fa90 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint32_t f_18;
    std::uint8_t f_1c;
    std::uint8_t unk_1d[0x3];
    std::uint64_t f_20;
    Obj_a4fa90() {
        refCount = 0u;
        vftable = Data_19a7f48;
        f_10 = 0u;
        f_18 = 0u;
        f_1c = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a4fc60 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint8_t f_20;
    std::uint8_t unk_21[0x7];
    std::uint64_t f_28;
    Obj_a4fc60() {
        refCount = 0u;
        vftable = Data_19a7fa8;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
        f_28 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a4fe30 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    std::uint64_t f_28;
    std::uint16_t f_30;
    std::uint8_t unk_32[0x6];
    std::uint64_t f_38;
    Obj_a4fe30() {
        refCount = 0u;
        vftable = Data_19a8008;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
        f_28 = 0u;
        f_30 = 0u;
        f_38 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50000 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    Obj_a50000() {
        refCount = 0u;
        vftable = Data_19a8068;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a501c0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    Obj_a501c0() {
        refCount = 0u;
        vftable = Data_19a80c8;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50390 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint8_t unk_10[0x4];
    std::uint32_t f_14;
    std::uint8_t f_18;
    std::uint8_t unk_19[0x7];
    std::uint64_t f_20;
    Obj_a50390() {
        refCount = 0u;
        vftable = Data_19a8128;
        f_14 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50570 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint8_t unk_10[0x4];
    std::uint32_t f_14;
    std::uint8_t f_18;
    std::uint8_t unk_19[0x7];
    std::uint64_t f_20;
    Obj_a50570() {
        refCount = 0u;
        vftable = Data_19a8188;
        f_14 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50740 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    Obj_a50740() {
        refCount = 0u;
        vftable = Data_19a81e8;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50900 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    Obj_a50900() {
        refCount = 0u;
        f_10 = 0u;
        f_18 = 0u;
        vftable = Data_19a8248;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50ac0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    Obj_a50ac0() {
        refCount = 0u;
        vftable = Data_19a82a8;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50c90 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint64_t f_20;
    Obj_a50c90() {
        refCount = 0u;
        vftable = Data_19a8308;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a50e60 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0xc];
    std::uint64_t f_20;
    Obj_a50e60() {
        refCount = 0u;
        vftable = Data_19a8368;
        f_10 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a51020 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint32_t f_10;
    std::uint8_t unk_14[0x4];
    std::uint64_t f_18;
    std::uint8_t f_20;
    std::uint8_t unk_21[0x7];
    Obj_a51020() {
        refCount = 0u;
        vftable = Data_19a83c8;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a511f0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint8_t unk_20[0x8];
    std::uint64_t f_28;
    Obj_a511f0() {
        refCount = 0u;
        vftable = Data_19a8428;
        f_10 = 0u;
        f_18 = 0u;
        f_28 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a513c0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    Obj_a513c0() {
        refCount = 0u;
        vftable = Data_19a8488;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a51690 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    Obj_a51690() {
        refCount = 0u;
        vftable = Data_19a84e8;
        f_10 = 0u;
        f_18 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct Obj_a519b0 : HeapAllocBase {
    void* vftable;
    std::uint64_t refCount;
    std::uint64_t f_10;
    std::uint64_t f_18;
    std::uint8_t f_20;
    std::uint8_t unk_21[0x7];
    Obj_a519b0() {
        refCount = 0u;
        vftable = Data_19a8e90;
        f_10 = 0u;
        f_18 = 0u;
        f_20 = 0u;
    }
    void Destroy() throw() {
        using DtorFn = void(__fastcall*)(void*, std::uint32_t);
        (*reinterpret_cast<DtorFn*>(vftable))(this, 1u);
    }
    void IncRef() throw() {
        _InterlockedIncrement(reinterpret_cast<volatile long*>(&refCount));  // atomic refcount increment
    }
    std::uint32_t DecRef() throw() {
        return static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&refCount)));  // atomic refcount decrement
    }
};

struct BSTSmartPointerCreate {
    void Op3e13b0(MemoryFactorySmartPtr<Obj_3e13b0>& out);
    void Op3f0e80(MemoryFactorySmartPtr<Obj_3f0e80>& out);
    void Opa09090(MemoryFactorySmartPtr<Obj_a09090>& out);
    void Opa09260(MemoryFactorySmartPtr<Obj_a09260>& out);
    void Opa09420(MemoryFactorySmartPtr<Obj_a09420>& out);
    void Opa28dc0(MemoryFactorySmartPtr<Obj_a28dc0>& out);
    void Opa321c0(MemoryFactorySmartPtr<Obj_a321c0>& out);
    void Opa33690(MemoryFactorySmartPtr<Obj_a33690>& out);
    void Opa35f40(MemoryFactorySmartPtr<Obj_a35f40>& out);
    void Opa4fa90(MemoryFactorySmartPtr<Obj_a4fa90>& out);
    void Opa4fc60(MemoryFactorySmartPtr<Obj_a4fc60>& out);
    void Opa4fe30(MemoryFactorySmartPtr<Obj_a4fe30>& out);
    void Opa50000(MemoryFactorySmartPtr<Obj_a50000>& out);
    void Opa501c0(MemoryFactorySmartPtr<Obj_a501c0>& out);
    void Opa50390(MemoryFactorySmartPtr<Obj_a50390>& out);
    void Opa50570(MemoryFactorySmartPtr<Obj_a50570>& out);
    void Opa50740(MemoryFactorySmartPtr<Obj_a50740>& out);
    void Opa50900(MemoryFactorySmartPtr<Obj_a50900>& out);
    void Opa50ac0(MemoryFactorySmartPtr<Obj_a50ac0>& out);
    void Opa50c90(MemoryFactorySmartPtr<Obj_a50c90>& out);
    void Opa50e60(MemoryFactorySmartPtr<Obj_a50e60>& out);
    void Opa51020(MemoryFactorySmartPtr<Obj_a51020>& out);
    void Opa511f0(MemoryFactorySmartPtr<Obj_a511f0>& out);
    void Opa513c0(MemoryFactorySmartPtr<Obj_a513c0>& out);
    void Opa51690(MemoryFactorySmartPtr<Obj_a51690>& out);
    void Opa519b0(MemoryFactorySmartPtr<Obj_a519b0>& out);
};
