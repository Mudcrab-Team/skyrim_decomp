// Source exposure: binary-analysis
// Static1bac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1bac0;
extern void construct(Static1bac0*, const Descriptor*);
extern void destroy(Static1bac0*);
struct Static1bac0 {
    void* value;
    Static1bac0() { construct(this, &descriptor); }
    ~Static1bac0() { destroy(this); }
};
