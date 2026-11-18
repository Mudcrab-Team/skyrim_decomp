// Source exposure: binary-analysis
// Static1bdf0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1bdf0;
extern void construct(Static1bdf0*, const Descriptor*);
extern void destroy(Static1bdf0*);
struct Static1bdf0 {
    void* value;
    Static1bdf0() { construct(this, &descriptor); }
    ~Static1bdf0() { destroy(this); }
};
