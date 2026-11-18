// Source exposure: binary-analysis
// Static1b0d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b0d0;
extern void construct(Static1b0d0*, const Descriptor*);
extern void destroy(Static1b0d0*);
struct Static1b0d0 {
    void* value;
    Static1b0d0() { construct(this, &descriptor); }
    ~Static1b0d0() { destroy(this); }
};
