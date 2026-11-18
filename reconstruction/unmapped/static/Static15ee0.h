// Source exposure: binary-analysis
// Static15ee0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15ee0;
extern void construct(Static15ee0*, const Descriptor*);
extern void destroy(Static15ee0*);
struct Static15ee0 {
    void* value;
    Static15ee0() { construct(this, &descriptor); }
    ~Static15ee0() { destroy(this); }
};
