// Source exposure: binary-analysis
// Static1033d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1033d0;
extern void construct(Static1033d0*, const Descriptor*);
extern void destroy(Static1033d0*);
struct Static1033d0 {
    void* value;
    Static1033d0() { construct(this, &descriptor); }
    ~Static1033d0() { destroy(this); }
};
