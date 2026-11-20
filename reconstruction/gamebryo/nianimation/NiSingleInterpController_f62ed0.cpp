// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xf62ed0 NiSingleInterpController::RegisterStreamables
// 0xf62f20 NiSingleInterpController::SaveBinary
// 0xf63020 NiSingleInterpController::SetInterpolator
// 0xf630d0 NiSingleInterpController::ProcessClone
#include "NiSingleInterpController_f62ed0.h"

class BSFixedString;
class NiBinaryStream;

// NiStream, SaveLinkID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream
{
public:
    virtual ~NiStream();
    virtual bool Load1(NiBinaryStream* stream);
    virtual bool Load2(char* buffer, std::uint64_t length);
    virtual bool Load3(const char* path);
    virtual bool Save1(NiBinaryStream* stream);
    virtual bool Save2(char*& path, std::uint64_t& length);
    virtual bool Save3(const char* path);
    virtual bool Unk_07();
    virtual bool RegisterFixedString(const BSFixedString& value);
    virtual bool RegisterSaveObject(NiObject* object);
    virtual bool ChangeObject(NiObject* object);
    virtual std::uint32_t GetLinkIDFromObject(const NiObject* object);
    virtual void SaveLinkID(const NiObject* object);
};

bool NiSingleInterpController::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiInterpController::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (interpolator) {
        interpolator->RegisterStreamables(stream);
    }
    return true;
}

void NiSingleInterpController::SaveBinary(NiStream& stream)
{
    NiInterpController::SaveBinary(stream);
    return stream.SaveLinkID(interpolator);
}

void NiSingleInterpController::SetInterpolator(NiInterpolator* value, std::uint16_t index)
{
    auto* previous = interpolator;
    if (previous != value) {
        if (value) {
            // A new interpolator takes an atomic reference before publication.
            _InterlockedIncrement(reinterpret_cast<volatile long*>(&value->_refCount));
        }
        interpolator = value;
        // Release the old reference atomically and test its value before the decrement.
        if (previous && _InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&previous->_refCount), -1) == 1) {
            return previous->DeleteThis();
        }
    }
}

void NiSingleInterpController::ProcessClone(NiCloningProcess& cloning)
{
    NiTimeController::ProcessClone(cloning);
    if (interpolator) {
        interpolator->ProcessClone(cloning);
    }
}
