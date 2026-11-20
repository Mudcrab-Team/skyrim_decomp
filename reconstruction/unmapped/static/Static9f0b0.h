// Source exposure: binary-analysis
// Static9f0b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f0b0;
extern void construct(Static9f0b0*, const Descriptor*);
extern void destroy(Static9f0b0*);
struct Static9f0b0 {
    void* value;
    Static9f0b0() { construct(this, &descriptor); }
    ~Static9f0b0() { destroy(this); }
};
