// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiKeyBasedInterpolator, NiKeyBasedInterpolator::GetActiveTimeRange_140CDC7B0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiAnimationKeyf6e870, GetKeyChannelCount, GetKeyCount, GetKeyArray, GetKeySize, GetKeyAt, time: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct NiAnimationKeyf6e870
{
    float time;  // 00
};

class NiKeyBasedInterpolator
{
public:
    virtual ~NiKeyBasedInterpolator();
    virtual void Unk_01(); virtual void Unk_02(); virtual void Unk_03(); virtual void Unk_04();
    virtual void Unk_05(); virtual void Unk_06(); virtual void Unk_07(); virtual void Unk_08();
    virtual void Unk_09(); virtual void Unk_0A(); virtual void Unk_0B(); virtual void Unk_0C();
    virtual void Unk_0D(); virtual void Unk_0E(); virtual void Unk_0F(); virtual void Unk_10();
    virtual void Unk_11(); virtual void Unk_12(); virtual void Unk_13(); virtual void Unk_14();
    virtual void Unk_15(); virtual void Unk_16(); virtual void Unk_17(); virtual void Unk_18();
    virtual void Unk_19(); virtual void Unk_1A(); virtual void Unk_1B(); virtual void Unk_1C();
    virtual void Unk_1D(); virtual void Unk_1E(); virtual void Unk_1F(); virtual void Unk_20();
    virtual void Unk_21(); virtual void Unk_22(); virtual void Unk_23(); virtual void Unk_24();
    virtual void Unk_25(); virtual void Unk_26(); virtual void Unk_27(); virtual void Unk_28();
    virtual void Unk_29(); virtual void Unk_2A(); virtual void Unk_2B(); virtual void Unk_2C();
    virtual void Unk_2D(); virtual void Unk_2E(); virtual void Unk_2F(); virtual void Unk_30();
    virtual void Unk_31(); virtual void Unk_32(); virtual void Unk_33(); virtual void Unk_34();
    virtual void Unk_35(); virtual void Unk_36(); virtual void Unk_37(); virtual void Unk_38();
    virtual std::uint16_t GetKeyChannelCount() const;            // 39 (0x1C8)
    virtual std::uint32_t GetKeyCount(std::uint16_t a_ch) const; // 3A (0x1D0)
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual NiAnimationKeyf6e870* GetKeyArray(std::uint16_t a_ch) const;  // 3D (0x1E8)
    virtual std::uint8_t GetKeySize(std::uint16_t a_ch) const;            // 3E (0x1F0)

    NiAnimationKeyf6e870* GetKeyAt(std::uint32_t a_index, std::uint16_t a_ch) const
    {
        std::uint8_t keySize = GetKeySize(a_ch);
        NiAnimationKeyf6e870* arr = GetKeyArray(a_ch);
        return reinterpret_cast<NiAnimationKeyf6e870*>(
            reinterpret_cast<char*>(arr) + static_cast<std::uint32_t>(keySize) * a_index);
    }

    void GetActiveTimeRange_140CDC7B0(float& a_begin, float& a_end) const;  // compared: 0xf6e870
};
