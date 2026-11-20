// Source exposure: binary-analysis
// Static1010b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1010b0;
extern void construct(Static1010b0*, const Descriptor*);
extern void destroy(Static1010b0*);
struct Static1010b0 {
    void* value;
    Static1010b0() { construct(this, &descriptor); }
    ~Static1010b0() { destroy(this); }
};
