// Source exposure: binary-analysis
// Static9e7e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e7e0;
extern void construct(Static9e7e0*, const Descriptor*);
extern void destroy(Static9e7e0*);
struct Static9e7e0 {
    void* value;
    Static9e7e0() { construct(this, &descriptor); }
    ~Static9e7e0() { destroy(this); }
};
