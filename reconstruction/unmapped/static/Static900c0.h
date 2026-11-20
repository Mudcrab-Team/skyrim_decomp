// Source exposure: binary-analysis
// Static900c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static900c0;
extern void construct(Static900c0*, const Descriptor*);
extern void destroy(Static900c0*);
struct Static900c0 {
    void* value;
    Static900c0() { construct(this, &descriptor); }
    ~Static900c0() { destroy(this); }
};
