// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// DetectionState, DetectionState::level, DetectionState::hasLOS, DetectionState::unk15, DetectionState::unk16, DetectionState::unk18, DetectionState::unk1C, DetectionState::unk28, DetectionState::unk2C, DetectionState::unk38, DetectionState::unk3C, NiPoint3, NiRefObject: CRASHLOGGER_PDB(59818@2026.10.24)
// gNiPoint3Zero, gNiRefObjectCount: GUESS
#pragma once

#include <cstdint>
#include <intrin.h>

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3(const NiPoint3& a_rhs) : x(a_rhs.x), y(a_rhs.y), z(a_rhs.z) {}
};

extern const NiPoint3 gNiPoint3Zero;
extern long gNiRefObjectCount;

class NiRefObject
{
  public:
    NiRefObject() : _refCount(0)
    {
        // Engine tracks total live NiRefObject instances atomically.
        _InterlockedIncrement(&gNiRefObjectCount);
    }

    virtual ~NiRefObject();

    std::uint32_t _refCount;
    std::uint32_t unk0C;
};

class DetectionState : public NiRefObject
{
  public:
    DetectionState();
    ~DetectionState() override;

    std::int32_t level;
    bool hasLOS;
    bool unk15;
    bool unk16;
    float unk18;
    NiPoint3 unk1C;
    float unk28;
    NiPoint3 unk2C;
    float unk38;
    NiPoint3 unk3C;
};

static_assert(sizeof(DetectionState) == 0x48, "DetectionState size");
