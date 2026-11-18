// Source exposure: binary-analysis
// Static9a0c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9a0c0;
extern void construct(Static9a0c0*, const Descriptor*);
extern void destroy(Static9a0c0*);
struct Static9a0c0 {
    void* value;
    Static9a0c0() { construct(this, &descriptor); }
    ~Static9a0c0() { destroy(this); }
};
