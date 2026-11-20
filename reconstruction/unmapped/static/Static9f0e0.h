// Source exposure: binary-analysis
// Static9f0e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f0e0;
extern void construct(Static9f0e0*, const Descriptor*);
extern void destroy(Static9f0e0*);
struct Static9f0e0 {
    void* value;
    Static9f0e0() { construct(this, &descriptor); }
    ~Static9f0e0() { destroy(this); }
};
