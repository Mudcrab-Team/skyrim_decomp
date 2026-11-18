// Source exposure: binary-analysis
// Static1b3a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b3a0;
extern void construct(Static1b3a0*, const Descriptor*);
extern void destroy(Static1b3a0*);
struct Static1b3a0 {
    void* value;
    Static1b3a0() { construct(this, &descriptor); }
    ~Static1b3a0() { destroy(this); }
};
