// Source exposure: binary-analysis
// Static978a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static978a0;
extern void construct(Static978a0*, const Descriptor*);
extern void destroy(Static978a0*);
struct Static978a0 {
    void* value;
    Static978a0() { construct(this, &descriptor); }
    ~Static978a0() { destroy(this); }
};
