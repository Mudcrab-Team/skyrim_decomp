// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// FixedBuffer13a06d0, FormatVsnprintf13a06d0: GUESS(low) STANDIN
#pragma once

#include <cstdarg>
#include <cstddef>
#include <cstdint>

int FormatVsnprintf13a06d0(char* a_dst, std::size_t a_size, const char* a_fmt, std::va_list a_args);

struct FixedBuffer13a06d0
{
    void FormatV(const char* a_fmt, std::va_list a_args)
    {
        if (FormatVsnprintf13a06d0(nullptr, 0, a_fmt, a_args) >= 0) {
            int written = FormatVsnprintf13a06d0(data, sizeof(data), a_fmt, a_args);
            if (written < 0 || static_cast<std::size_t>(written) > sizeof(data) - 1) {
                length = sizeof(data) - 1;
            } else {
                length = static_cast<std::size_t>(written);
            }
        }
    }

    FixedBuffer13a06d0& Format(const char* a_fmt, ...);  // compared: 0x13a06d0

    std::uint64_t unk00;  // 0x00
    std::size_t length;   // 0x08
    char data[0x200];     // 0x10
};
