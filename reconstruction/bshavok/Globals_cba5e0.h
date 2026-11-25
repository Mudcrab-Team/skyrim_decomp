// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkMemoryStreamReader: CRASHLOGGER_PDB(59818@2026.10.24)
// hkMemoryStreamReader::Routine140BDE540: CRASHLOGGER_PDB(59818@2026.10.24)
// Globals: GUESS(low); placeholder name
#pragma once

struct hkMemoryStreamReader
{
    virtual void first();
    virtual void second();
    virtual void third();
    virtual unsigned char* checkState(unsigned char* state);

    int m_04;
    unsigned char* m_08;
    int m_0c;
    int m_10;

    int Routine140BDE540(void* destination, int count);
};
extern "C" void Func00cb1260(void* destination, const void* source, int count);

struct Globals
{
};
