// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cb990: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// FileTime1cb990, SystemTime1cb990, ToLocalTime, ToSystemTime: GUESS(low) STANDIN; imported timestamp conversion
struct FileTime1cb990 { unsigned low; unsigned high; };
struct SystemTime1cb990 { std::uint16_t year,month,dayOfWeek,day,hour,minute,second,milliseconds; };
extern "C" __declspec(dllimport) int ToLocalTime(const FileTime1cb990*, FileTime1cb990*);
extern "C" __declspec(dllimport) int ToSystemTime(const FileTime1cb990*, SystemTime1cb990*);

class TESFile
{
public:
    std::uint8_t unknown00[752];
    FileTime1cb990 time;

    void Function1cb990(SystemTime1cb990* output);
};
