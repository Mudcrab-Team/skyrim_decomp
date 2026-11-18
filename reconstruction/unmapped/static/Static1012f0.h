// Source exposure: binary-analysis
// Static1012f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1012f0;
extern void construct(Static1012f0*, const Descriptor*);
extern void destroy(Static1012f0*);
struct Static1012f0 {
    void* value;
    Static1012f0() { construct(this, &descriptor); }
    ~Static1012f0() { destroy(this); }
};
