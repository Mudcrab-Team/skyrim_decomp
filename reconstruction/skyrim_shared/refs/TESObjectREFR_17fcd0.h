// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESObjectREFR, sub_1401337A0: CRASHLOGGER_PDB(59818@2026.10.24)
// BSSpinLock, owningThread, lockCount, TryLock, Unlock, Virtual6C, lock90, GetCurrentThreadId, Unk_01..Unk_6B, unknown008: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();

struct BSSpinLock
{
    std::uint32_t owningThread;  // 00
    std::uint32_t lockCount;     // 04

    bool TryLock()
    {
        const std::uint32_t tid = GetCurrentThreadId();
        _mm_lfence();  // order lock owner read after thread-id query
        if (owningThread == tid) {
            _InterlockedIncrement(reinterpret_cast<long*>(&lockCount));  // increment recursive spin-lock count atomically
            return true;
        }
        const bool acquired = (_InterlockedCompareExchange(reinterpret_cast<long*>(&lockCount), 1, 0) == 0);  // acquire unowned spin lock atomically
        if (acquired) {
            owningThread = tid;
            _mm_sfence();  // publish lock owner before entering critical section
        }
        return acquired;
    }

    void Unlock()
    {
        _mm_lfence();  // order unlock state reads after critical section
        const std::uint32_t tid = GetCurrentThreadId();
        if (owningThread == tid) {
            if (lockCount == 1) {
                owningThread = 0;
                _mm_mfence();  // flush owner clear before releasing spin lock
                _InterlockedCompareExchange(reinterpret_cast<long*>(&lockCount), 0, 1);  // release last spin-lock hold atomically
            } else {
                _InterlockedDecrement(reinterpret_cast<long*>(&lockCount));  // decrement recursive spin-lock count atomically
            }
        }
    }
};

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    virtual void Unk_5C();
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Virtual6C(void* arg1, bool arg2);  // 6C (0x360)

    void sub_1401337A0(void* arg1, bool arg2);

    std::uint8_t unknown008[0x88];  // 008
    BSSpinLock   lock90;            // 090
};
static_assert(offsetof(TESObjectREFR, lock90) == 0x90, "lock90 offset");
