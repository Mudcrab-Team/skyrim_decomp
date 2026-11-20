// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts of the occlusion shape and the box plane sets.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// BSOcclusionShape, BSOcclusionBox, NiAVObject, NiCloningProcess, NiPoint3, NiFrustumPlanes, updateFacesOrVertices, frustumPlanes, size: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CopyMembers, CopyPlaneSets, RebuildPlaneSets, CopyFrom: GUESS(low)
#pragma once

#include <cstdint>

class NiAVObject;
class NiCloningProcess;

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class NiFrustumPlanes
{
public:
    void CopyFrom(const NiFrustumPlanes& source);

private:
    std::uint8_t unknown00[0x70];
};

class BSOcclusionShape
{
public:
    void CopyMembers(BSOcclusionShape& destination, NiCloningProcess& cloning) const;

protected:
    std::uint8_t unknown00[0x44];
    bool updateFacesOrVertices;
    std::uint8_t unknown45[3];
};

class BSOcclusionBox : public BSOcclusionShape
{
public:
    void CopyMembers(BSOcclusionBox& destination, NiCloningProcess& cloning) const;
    bool CopyPlaneSets(const NiAVObject& viewpoint, NiFrustumPlanes& first, NiFrustumPlanes& second);

private:
    bool RebuildPlaneSets(const NiAVObject& viewpoint);

    NiPoint3 size;
    NiFrustumPlanes frustumPlanes[2];
};
