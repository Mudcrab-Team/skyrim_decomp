// Source exposure: binary-analysis
// Static1032b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1032b0;
extern void construct(Static1032b0*, const Descriptor*);
extern void destroy(Static1032b0*);
struct Static1032b0 {
    void* value;
    Static1032b0() { construct(this, &descriptor); }
    ~Static1032b0() { destroy(this); }
};
