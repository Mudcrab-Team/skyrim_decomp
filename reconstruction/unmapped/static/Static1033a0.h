// Source exposure: binary-analysis
// Static1033a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1033a0;
extern void construct(Static1033a0*, const Descriptor*);
extern void destroy(Static1033a0*);
struct Static1033a0 {
    void* value;
    Static1033a0() { construct(this, &descriptor); }
    ~Static1033a0() { destroy(this); }
};
