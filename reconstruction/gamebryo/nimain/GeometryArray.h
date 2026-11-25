// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: Original array cleanup reconstructed from the two geometry destructors.
// BSTArrayHeapAllocator and BSTArrayBase: CRASHLOGGER_PDB(59818@2026.10.24)
// GeometryArray, Deallocate and Clear: GUESS(low) STANDIN
#pragma once

struct BSTArrayHeapAllocator {
    BSTArrayHeapAllocator();
    ~BSTArrayHeapAllocator();
    void Deallocate();
    void* data;
    unsigned int capacity;
};
struct BSTArrayBase {
    BSTArrayBase();
    ~BSTArrayBase();
    unsigned int size;
};
template <class T>
struct GeometryArray : BSTArrayHeapAllocator, BSTArrayBase {
    void Clear()
    {
        if (data) {
            Deallocate();
            size = 0;
        }
    }
    ~GeometryArray() { Clear(); }
};
