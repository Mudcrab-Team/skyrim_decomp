// Source exposure: binary-analysis
// Static243e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static243e0;
extern void construct(Static243e0*, const Descriptor*);
extern void destroy(Static243e0*);
struct Static243e0 {
    void* value;
    Static243e0() { construct(this, &descriptor); }
    ~Static243e0() { destroy(this); }
};
