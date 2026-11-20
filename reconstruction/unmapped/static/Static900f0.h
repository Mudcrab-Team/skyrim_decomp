// Source exposure: binary-analysis
// Static900f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static900f0;
extern void construct(Static900f0*, const Descriptor*);
extern void destroy(Static900f0*);
struct Static900f0 {
    void* value;
    Static900f0() { construct(this, &descriptor); }
    ~Static900f0() { destroy(this); }
};
