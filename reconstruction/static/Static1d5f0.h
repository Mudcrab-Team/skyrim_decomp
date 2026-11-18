// Source exposure: binary-analysis
// Static1d5f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d5f0;
extern void construct(Static1d5f0*, const Descriptor*);
extern void destroy(Static1d5f0*);
struct Static1d5f0 {
    void* value;
    Static1d5f0() { construct(this, &descriptor); }
    ~Static1d5f0() { destroy(this); }
};
