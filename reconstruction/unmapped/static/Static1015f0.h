// Source exposure: binary-analysis
// Static1015f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1015f0;
extern void construct(Static1015f0*, const Descriptor*);
extern void destroy(Static1015f0*);
struct Static1015f0 {
    void* value;
    Static1015f0() { construct(this, &descriptor); }
    ~Static1015f0() { destroy(this); }
};
