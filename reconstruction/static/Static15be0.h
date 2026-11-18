// Source exposure: binary-analysis
// Static15be0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15be0;
extern void construct(Static15be0*, const Descriptor*);
extern void destroy(Static15be0*);
struct Static15be0 {
    void* value;
    Static15be0() { construct(this, &descriptor); }
    ~Static15be0() { destroy(this); }
};
