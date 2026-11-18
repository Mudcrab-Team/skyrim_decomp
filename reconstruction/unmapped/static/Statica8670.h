// Source exposure: binary-analysis; possible sibling implementation exposure disclosed below.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00cc0000_o2.cpp:13192 (ContextScope helper).
// ContextScope lineage is uncertain; conservatively treated as adapted from that sibling source.
// ContextScope: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); no licence is granted by its authors.
// Statica8670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Statica8670;
struct Manager {
    virtual void reserved();
    virtual void construct(Statica8670*);
    virtual void release(Statica8670*);
};
extern Manager* manager();
// current_context, previous, Storage: GUESS(low) STANDIN
// ContextScope: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Thread-local storage models a separate context selection for each thread.
extern __declspec(thread) int current_context;
struct ContextScope {
    int previous;
    ContextScope() : previous(current_context) { current_context = 102; }
    ~ContextScope() { current_context = previous; }
};
struct Storage { void* value; ~Storage(); };
struct Statica8670 {
    Storage value;
    Statica8670() { ContextScope scope; manager()->construct(this); }
    ~Statica8670();
};
