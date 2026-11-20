// Source exposure: binary-analysis
// Static1d4d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d4d0;
extern void construct(Static1d4d0*, const Descriptor*);
extern void destroy(Static1d4d0*);
struct Static1d4d0 {
    void* value;
    Static1d4d0() { construct(this, &descriptor); }
    ~Static1d4d0() { destroy(this); }
};
