// Source exposure: binary-analysis
// Static9f6a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f6a0;
extern void construct(Static9f6a0*, const Descriptor*);
extern void destroy(Static9f6a0*);
struct Static9f6a0 {
    void* value;
    Static9f6a0() { construct(this, &descriptor); }
    ~Static9f6a0() { destroy(this); }
};
