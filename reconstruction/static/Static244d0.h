// Source exposure: binary-analysis
// Static244d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static244d0;
extern void construct(Static244d0*, const Descriptor*);
extern void destroy(Static244d0*);
struct Static244d0 {
    void* value;
    Static244d0() { construct(this, &descriptor); }
    ~Static244d0() { destroy(this); }
};
