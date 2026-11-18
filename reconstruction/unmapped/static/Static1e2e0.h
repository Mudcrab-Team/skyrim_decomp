// Source exposure: binary-analysis
// Static1e2e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e2e0;
extern void construct(Static1e2e0*, const Descriptor*);
extern void destroy(Static1e2e0*);
struct Static1e2e0 {
    void* value;
    Static1e2e0() { construct(this, &descriptor); }
    ~Static1e2e0() { destroy(this); }
};
