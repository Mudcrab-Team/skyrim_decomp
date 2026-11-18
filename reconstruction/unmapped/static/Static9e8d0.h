// Source exposure: binary-analysis
// Static9e8d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9e8d0;
extern void construct(Static9e8d0*, const Descriptor*);
extern void destroy(Static9e8d0*);
struct Static9e8d0 {
    void* value;
    Static9e8d0() { construct(this, &descriptor); }
    ~Static9e8d0() { destroy(this); }
};
