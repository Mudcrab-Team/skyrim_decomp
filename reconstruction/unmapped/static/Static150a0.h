// Source exposure: binary-analysis
// Static150a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static150a0;
extern void construct(Static150a0*, const Descriptor*);
extern void destroy(Static150a0*);
struct Static150a0 {
    void* value;
    Static150a0() { construct(this, &descriptor); }
    ~Static150a0() { destroy(this); }
};
