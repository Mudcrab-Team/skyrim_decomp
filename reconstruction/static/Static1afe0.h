// Source exposure: binary-analysis
// Static1afe0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1afe0;
extern void construct(Static1afe0*, const Descriptor*);
extern void destroy(Static1afe0*);
struct Static1afe0 {
    void* value;
    Static1afe0() { construct(this, &descriptor); }
    ~Static1afe0() { destroy(this); }
};
