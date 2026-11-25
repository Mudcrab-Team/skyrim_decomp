// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1cb9d0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// FileTime1cb9d0, SystemTime1cb9d0, ToLocalTime, ToSystemTime: GUESS(low) STANDIN; imported timestamp conversion
struct FileTime1cb9d0 { unsigned low; unsigned high; };
struct SystemTime1cb9d0 { std::uint16_t year,month,dayOfWeek,day,hour,minute,second,milliseconds; };
extern "C" __declspec(dllimport) int ToLocalTime(const FileTime1cb9d0*, FileTime1cb9d0*);
extern "C" __declspec(dllimport) int ToSystemTime(const FileTime1cb9d0*, SystemTime1cb9d0*);

class TESFile
{
public:
    std::uint8_t unknown00[768];
    FileTime1cb9d0 time;

    void Function1cb9d0(SystemTime1cb9d0* output);
};
