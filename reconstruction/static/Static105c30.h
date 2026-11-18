// Recipe: reconstruction/recipes/o2-os.json
// Source exposure: binary-analysis; possible sibling implementation exposure disclosed below.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00cc0000_o2.cpp:13192 (ContextScope helper).
// ContextScope lineage is uncertain; conservatively treated as adapted from that sibling source.
// ContextScope: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); no licence is granted by its authors.
// Static105c30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static105c30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static105c30*);
    virtual void release(Static105c30*);
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
struct Static105c30 {
    Storage value;
    // Inline the thin scoped dispatch wrapper to avoid a separate constructor call for each static instance.
    __forceinline Static105c30() { ContextScope scope; manager()->construct(this); }
    ~Static105c30();
};
