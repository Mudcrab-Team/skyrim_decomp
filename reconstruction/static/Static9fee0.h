// Source exposure: binary-analysis
// Static9fee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9fee0;
extern void construct(Static9fee0*, const Descriptor*);
extern void destroy(Static9fee0*);
struct Static9fee0 {
    void* value;
    Static9fee0() { construct(this, &descriptor); }
    ~Static9fee0() { destroy(this); }
};
