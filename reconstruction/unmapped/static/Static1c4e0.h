// Source exposure: binary-analysis
// Static1c4e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1c4e0;
extern void construct(Static1c4e0*, const Descriptor*);
extern void destroy(Static1c4e0*);
struct Static1c4e0 {
    void* value;
    Static1c4e0() { construct(this, &descriptor); }
    ~Static1c4e0() { destroy(this); }
};
