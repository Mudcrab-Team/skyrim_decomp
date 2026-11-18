// Source exposure: binary-analysis
// Static1dfe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1dfe0;
extern void construct(Static1dfe0*, const Descriptor*);
extern void destroy(Static1dfe0*);
struct Static1dfe0 {
    void* value;
    Static1dfe0() { construct(this, &descriptor); }
    ~Static1dfe0() { destroy(this); }
};
