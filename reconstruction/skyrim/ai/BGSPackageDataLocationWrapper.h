// Source exposure: mixed (pinned image listing and public names).
// Code origin: existing leaf plus original reconstruction of Function44e3f0.
// BGSPackageDataLocationWrapper: EXE_RTTI
// Slot5, Function44e3f0, PackageLocationTarget, loadedLocation, target: GUESS(low)
#pragma once
#include <cstdint>

class BGSLoadGameBuffer;

class PackageLocationTarget
{
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual bool Slot5(void* a_arg);
};

PackageLocationTarget* ReadPackageLocation(BGSLoadGameBuffer& a_buffer);

class BGSPackageDataLocationWrapper
{
public:
    virtual std::uint8_t Slot5() const;
    bool Function44e3f0(void* a_unused, void* a_arg);

    void LoadGame(BGSLoadGameBuffer& a_buffer);

    PackageLocationTarget* loadedLocation;
    PackageLocationTarget* target;
};
