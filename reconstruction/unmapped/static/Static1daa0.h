// Source exposure: binary-analysis
// Static1daa0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1daa0;
extern void construct(Static1daa0*, const Descriptor*);
extern void destroy(Static1daa0*);
struct Static1daa0 {
    void* value;
    Static1daa0() { construct(this, &descriptor); }
    ~Static1daa0() { destroy(this); }
};
