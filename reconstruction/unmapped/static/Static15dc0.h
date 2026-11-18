// Source exposure: binary-analysis
// Static15dc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15dc0;
extern void construct(Static15dc0*, const Descriptor*);
extern void destroy(Static15dc0*);
struct Static15dc0 {
    void* value;
    Static15dc0() { construct(this, &descriptor); }
    ~Static15dc0() { destroy(this); }
};
