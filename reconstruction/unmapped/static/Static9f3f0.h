// Source exposure: binary-analysis
// Static9f3f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f3f0;
extern void construct(Static9f3f0*, const Descriptor*);
extern void destroy(Static9f3f0*);
struct Static9f3f0 {
    void* value;
    Static9f3f0() { construct(this, &descriptor); }
    ~Static9f3f0() { destroy(this); }
};
