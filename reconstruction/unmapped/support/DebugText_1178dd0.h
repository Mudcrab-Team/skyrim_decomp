// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// DebugText, DebugText::Func6_140ED1B90: CRASHLOGGER_PDB(59818@2026.10.24)
// DebugText::Unk_00, DebugText::Unk_01, DebugText::Unk_02, DebugText::Unk_03, DebugText::Unk_04, DebugText::Unk_05, DebugText::Unk_06, DebugText::VPrint: GUESS
#pragma once

#include <cstdarg>

class DebugText
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void VPrint(int a_x, int a_y, const char* a_fmt, std::va_list a_args, void* a_context);

    void Func6_140ED1B90(int a_x, int a_y, const char* a_fmt, ...);
};
