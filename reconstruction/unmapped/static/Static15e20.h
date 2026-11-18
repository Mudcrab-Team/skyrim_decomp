// Source exposure: binary-analysis
// Static15e20, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15e20;
extern void construct(Static15e20*, const Descriptor*);
extern void destroy(Static15e20*);
struct Static15e20 {
    void* value;
    Static15e20() { construct(this, &descriptor); }
    ~Static15e20() { destroy(this); }
};
