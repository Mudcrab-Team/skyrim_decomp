// Source exposure: binary-analysis
// Static15af0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15af0;
extern void construct(Static15af0*, const Descriptor*);
extern void destroy(Static15af0*);
struct Static15af0 {
    void* value;
    Static15af0() { construct(this, &descriptor); }
    ~Static15af0() { destroy(this); }
};
