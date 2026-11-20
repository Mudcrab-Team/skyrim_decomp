// Source exposure: binary-analysis
// Static979f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static979f0;
extern void construct(Static979f0*, const Descriptor*);
extern void destroy(Static979f0*);
struct Static979f0 {
    void* value;
    Static979f0() { construct(this, &descriptor); }
    ~Static979f0() { destroy(this); }
};
