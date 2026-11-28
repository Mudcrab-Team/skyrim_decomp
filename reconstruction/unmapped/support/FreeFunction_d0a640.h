// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// LoggerBase1d0a640, LoggerBase2d0a640, LoggerDerivedd0a640, Functiond0a640: GUESS(low) STANDIN
#pragma once

#include <cstdarg>
#include <cstdint>

struct LoggerBase1d0a640
{
    virtual ~LoggerBase1d0a640();
    virtual void LogMessageVarg(std::uint32_t a_messageType, const char* a_fmt, std::va_list a_args);

    std::uint64_t unk08;  // 0x08
    std::uint64_t unk10;  // 0x10
};

struct LoggerBase2d0a640
{
    std::uint64_t unk00;  // 0x00
};

struct LoggerDerivedd0a640 : public LoggerBase1d0a640, public LoggerBase2d0a640
{
};

void Functiond0a640(LoggerBase2d0a640* a_self, const char* a_fmt, ...);  // compared: 0xd0a640
