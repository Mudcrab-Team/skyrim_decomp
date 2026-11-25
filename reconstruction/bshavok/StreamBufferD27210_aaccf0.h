// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// StreamBufferD27210: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// StreamBufferD27210::FlushToDestination: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
#pragma once

struct BufferedStreamDestination;


struct BufferedStreamDestination
{
    virtual void vfn_0000();
    virtual void vfn_0004();
    virtual void vfn_0008();
    virtual void vfn_000c();
    virtual int Write(const void* source, int bytes);
};
struct StreamBufferD27210
{
    void* unk00;
    void* unk04;
    BufferedStreamDestination* m_destination;
    char* m_buffer;
    int m_vContactPosition;
    int m_kRayEnd;
    int FlushToDestination();
};
