// Source exposure: binary-analysis
// Static1036a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1036a0;
extern void construct(Static1036a0*, const Descriptor*);
extern void destroy(Static1036a0*);
struct Static1036a0 {
    void* value;
    Static1036a0() { construct(this, &descriptor); }
    ~Static1036a0() { destroy(this); }
};
