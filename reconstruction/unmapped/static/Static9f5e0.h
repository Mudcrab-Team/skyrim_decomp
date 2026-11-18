// Source exposure: binary-analysis
// Static9f5e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f5e0;
extern void construct(Static9f5e0*, const Descriptor*);
extern void destroy(Static9f5e0*);
struct Static9f5e0 {
    void* value;
    Static9f5e0() { construct(this, &descriptor); }
    ~Static9f5e0() { destroy(this); }
};
