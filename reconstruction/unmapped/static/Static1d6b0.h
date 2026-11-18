// Source exposure: binary-analysis
// Static1d6b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1d6b0;
extern void construct(Static1d6b0*, const Descriptor*);
extern void destroy(Static1d6b0*);
struct Static1d6b0 {
    void* value;
    Static1d6b0() { construct(this, &descriptor); }
    ~Static1d6b0() { destroy(this); }
};
