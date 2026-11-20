// Source exposure: binary-analysis.
// Code origin: original partial path request layout from local observations.
// PathingRequestFlee: EXE_RTTI
// PathingRequest, PathingOptions, PathingReader, PathingWriter, CopyMembers, Save, Load, CopyOptions, retreatDistance, requestFlags: GUESS(low)
#pragma once

#include <cstdint>

class PathingReader
{
public:
    virtual ~PathingReader();
    virtual void ReadFloat(float& value) = 0;
};

class PathingWriter
{
public:
    virtual ~PathingWriter();
    virtual void WriteFloat(float value) = 0;
};

struct PathingOptions
{
    void CopyFrom(const PathingOptions& source);

    std::uint8_t unknown00[0x2b];
    std::uint8_t requestFlags;
};

class PathingRequest
{
public:
    void CopyMembers(PathingRequest& destination) const;
    void Save(PathingWriter& stream) const;
    void Load(PathingReader& stream);

protected:
    std::uint8_t unknown00[0x58];
    PathingOptions options;
    std::uint8_t unknown84[0x7c];
};

class PathingRequestFlee : public PathingRequest
{
public:
    void CopyMembers(PathingRequestFlee& destination) const;
    void Save(PathingWriter& stream) const;
    void Load(PathingReader& stream);
    void CopyOptions(const PathingOptions& source);

private:
    float retreatDistance;
};
