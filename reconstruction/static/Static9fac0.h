// Source exposure: binary-analysis
// Static9fac0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fac0;
extern void construct(Static9fac0*, const Descriptor*);
extern void destroy(Static9fac0*);
struct Static9fac0 {
    void* value;
    Static9fac0() { construct(this, &descriptor); }
    ~Static9fac0() { destroy(this); }
};
