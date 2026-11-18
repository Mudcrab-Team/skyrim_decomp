// Source exposure: binary-analysis
// Static1e1f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e1f0;
extern void construct(Static1e1f0*, const Descriptor*);
extern void destroy(Static1e1f0*);
struct Static1e1f0 {
    void* value;
    Static1e1f0() { construct(this, &descriptor); }
    ~Static1e1f0() { destroy(this); }
};
