// Source exposure: binary-analysis
// Static1e1c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1e1c0;
extern void construct(Static1e1c0*, const Descriptor*);
extern void destroy(Static1e1c0*);
struct Static1e1c0 {
    void* value;
    Static1e1c0() { construct(this, &descriptor); }
    ~Static1e1c0() { destroy(this); }
};
