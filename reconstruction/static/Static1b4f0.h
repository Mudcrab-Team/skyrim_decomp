// Source exposure: binary-analysis
// Static1b4f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1b4f0;
extern void construct(Static1b4f0*, const Descriptor*);
extern void destroy(Static1b4f0*);
struct Static1b4f0 {
    void* value;
    Static1b4f0() { construct(this, &descriptor); }
    ~Static1b4f0() { destroy(this); }
};
