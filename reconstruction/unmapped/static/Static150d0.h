// Source exposure: binary-analysis
// Static150d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static150d0;
extern void construct(Static150d0*, const Descriptor*);
extern void destroy(Static150d0*);
struct Static150d0 {
    void* value;
    Static150d0() { construct(this, &descriptor); }
    ~Static150d0() { destroy(this); }
};
