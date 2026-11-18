// Source exposure: binary-analysis
// Static1d7a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d7a0;
extern void construct(Static1d7a0*, const Descriptor*);
extern void destroy(Static1d7a0*);
struct Static1d7a0 {
    void* value;
    Static1d7a0() { construct(this, &descriptor); }
    ~Static1d7a0() { destroy(this); }
};
