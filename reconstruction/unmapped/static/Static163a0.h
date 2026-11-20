// Source exposure: binary-analysis
// Static163a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static163a0;
extern void construct(Static163a0*, const Descriptor*);
extern void destroy(Static163a0*);
struct Static163a0 {
    void* value;
    Static163a0() { construct(this, &descriptor); }
    ~Static163a0() { destroy(this); }
};
