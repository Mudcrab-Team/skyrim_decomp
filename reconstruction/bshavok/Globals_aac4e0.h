// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkBufferedStreamReader: CRASHLOGGER_PDB(59818@2026.10.24)
// hkBufferedStreamReader::isOk: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_18_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

struct Reader;


struct Reader
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual unsigned char* v3(unsigned char*);
};
struct hkBool
{
    unsigned char m_cBooleanValue;
    hkBool(bool v) : m_cBooleanValue(v)
    {}
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkBufferedStreamReader
{
  public:
    char padding_0_[16];
    Reader *reader;
    char padding_18_[8];
    int pos;
    int end;
    hkBool isOk();
};

struct Globals
{
};
