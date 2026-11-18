// Source exposure: binary-analysis
// Static1011d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static1011d0;
extern void construct(Static1011d0*, const Descriptor*);
extern void destroy(Static1011d0*);
struct Static1011d0 {
    void* value;
    Static1011d0() { construct(this, &descriptor); }
    ~Static1011d0() { destroy(this); }
};
