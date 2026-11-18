// Source exposure: binary-analysis
// Static1013b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1013b0;
extern void construct(Static1013b0*, const Descriptor*);
extern void destroy(Static1013b0*);
struct Static1013b0 {
    void* value;
    Static1013b0() { construct(this, &descriptor); }
    ~Static1013b0() { destroy(this); }
};
