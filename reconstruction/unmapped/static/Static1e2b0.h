// Source exposure: binary-analysis
// Static1e2b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e2b0;
extern void construct(Static1e2b0*, const Descriptor*);
extern void destroy(Static1e2b0*);
struct Static1e2b0 {
    void* value;
    Static1e2b0() { construct(this, &descriptor); }
    ~Static1e2b0() { destroy(this); }
};
