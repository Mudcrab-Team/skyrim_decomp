// Source exposure: binary-analysis
// Static806f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static806f0;
extern void construct(Static806f0*, const Descriptor*);
extern void destroy(Static806f0*);
struct Static806f0 {
    void* value;
    Static806f0() { construct(this, &descriptor); }
    ~Static806f0() { destroy(this); }
};
