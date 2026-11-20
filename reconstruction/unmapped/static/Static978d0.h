// Source exposure: binary-analysis
// Static978d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static978d0;
extern void construct(Static978d0*, const Descriptor*);
extern void destroy(Static978d0*);
struct Static978d0 {
    void* value;
    Static978d0() { construct(this, &descriptor); }
    ~Static978d0() { destroy(this); }
};
