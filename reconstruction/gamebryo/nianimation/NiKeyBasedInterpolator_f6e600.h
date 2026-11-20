// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiKeyBasedInterpolator: EXE_RTTI
// InterpolatorKeyDataPointer, pointer, Reset, Replace, NiTimeRangeInterpolator, ReadStreamObjectLink, CopyMembers, GetKeyAt, Slot25..Slot31, Slot39..Slot3C: GUESS(low)
// GetKeyArray, GetKeyStride: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::LoadBinary, NiObject::SaveBinary, NiObject::RegisterStreamables, NiObject::IsEqual, NiInterpolator::GetActiveTimeRange, NiInterpolator::GuaranteeTimeRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "bssystem/NiStream_19e930.h"

template <class T>
class InterpolatorKeyDataPointer
{
public:
    InterpolatorKeyDataPointer() = default;

    explicit InterpolatorKeyDataPointer(T* keys) : pointer(keys)
    {
        if (keys) {
            // Retain the supplied key data for the lifetime of the interpolator.
            _InterlockedIncrement(reinterpret_cast<volatile long*>(&keys->_refCount));
        }
    }

    void Reset(T* keys)
    {
        Replace(pointer, keys);
    }

    void Reset(const InterpolatorKeyDataPointer& source)
    {
        auto* old = pointer;
        auto* keys = source.pointer;
        Replace(old, keys);
    }

    T* pointer = nullptr;

private:
    void Replace(T* old, T* keys)
    {
        if (old != keys) {
            if (keys) {
                // Retain the incoming object before releasing the old object.
                _InterlockedIncrement(reinterpret_cast<volatile long*>(&keys->_refCount));
            }
            pointer = keys;
            if (old) {
                // Release the outgoing key data and delete it at its last reference.
                const auto count = static_cast<std::uint32_t>(_InterlockedDecrement(reinterpret_cast<volatile long*>(&old->_refCount)));
                if (count == 0) {
                    old->DeleteThis();
                }
            }
        }
    }
};

NiObject* ReadStreamObjectLink(NiStream& stream);

class NiTimeRangeInterpolator : public NiObject
{
public:
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void GetActiveTimeRange(float& start, float& end) const;
    virtual void GuaranteeTimeRange(float start, float end);
};

class NiKeyBasedInterpolator : public NiInterpolator
{
public:
    NiKeyBasedInterpolator();
    void CopyMembers(NiKeyBasedInterpolator* dest) const;
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool RegisterStreamables(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual void Slot3C();
    virtual std::uint8_t* GetKeyArray(std::uint16_t channel) const;
    virtual std::uint8_t GetKeyStride(std::uint16_t channel) const;
    ~NiKeyBasedInterpolator() override;
    std::uint8_t* GetKeyAt(std::uint32_t index, std::uint16_t channel) const;
};
