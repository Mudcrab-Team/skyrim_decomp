// Source exposure: binary-analysis
// Static15df0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15df0;
extern void construct(Static15df0*, const Descriptor*);
extern void destroy(Static15df0*);
struct Static15df0 {
    void* value;
    Static15df0() { construct(this, &descriptor); }
    ~Static15df0() { destroy(this); }
};
