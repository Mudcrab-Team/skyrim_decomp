// Source exposure: binary-analysis
// Static176c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static176c0;
extern void construct(Static176c0*, const Descriptor*);
extern void destroy(Static176c0*);
struct Static176c0 {
    void* value;
    Static176c0() { construct(this, &descriptor); }
    ~Static176c0() { destroy(this); }
};
