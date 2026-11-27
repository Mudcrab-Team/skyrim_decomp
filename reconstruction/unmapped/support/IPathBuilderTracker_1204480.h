// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// IPathBuilderTracker, IPathBuilderTracker::PostMessage1: CRASHLOGGER_PDB(59818@2026.10.24)
// IPathBuilderTracker::Unk_00, IPathBuilderTracker::Unk_01, IPathBuilderTracker::VPostMessage: GUESS
#pragma once

#include <cstdarg>

class IPathBuilderTracker
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void VPostMessage(int a_level, const char* a_fmt, std::va_list a_args);

    void PostMessage1(const char* a_fmt, ...);
};
