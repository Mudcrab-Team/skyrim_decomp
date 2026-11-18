// Source exposure: binary-analysis
// Static1d1a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d1a0;
extern void construct(Static1d1a0*, const Descriptor*);
extern void destroy(Static1d1a0*);
struct Static1d1a0 {
    void* value;
    Static1d1a0() { construct(this, &descriptor); }
    ~Static1d1a0() { destroy(this); }
};
