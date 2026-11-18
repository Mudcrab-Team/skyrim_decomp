// Source exposure: binary-analysis
// Static159d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static159d0;
extern void construct(Static159d0*, const Descriptor*);
extern void destroy(Static159d0*);
struct Static159d0 {
    void* value;
    Static159d0() { construct(this, &descriptor); }
    ~Static159d0() { destroy(this); }
};
