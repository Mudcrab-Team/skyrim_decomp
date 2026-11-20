// Source exposure: binary-analysis
// Static1d7d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d7d0;
extern void construct(Static1d7d0*, const Descriptor*);
extern void destroy(Static1d7d0*);
struct Static1d7d0 {
    void* value;
    Static1d7d0() { construct(this, &descriptor); }
    ~Static1d7d0() { destroy(this); }
};
