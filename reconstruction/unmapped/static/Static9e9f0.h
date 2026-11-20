// Source exposure: binary-analysis
// Static9e9f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e9f0;
extern void construct(Static9e9f0*, const Descriptor*);
extern void destroy(Static9e9f0*);
struct Static9e9f0 {
    void* value;
    Static9e9f0() { construct(this, &descriptor); }
    ~Static9e9f0() { destroy(this); }
};
