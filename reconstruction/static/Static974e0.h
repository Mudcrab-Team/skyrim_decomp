// Source exposure: binary-analysis
// Static974e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static974e0;
extern void construct(Static974e0*, const Descriptor*);
extern void destroy(Static974e0*);
struct Static974e0 {
    void* value;
    Static974e0() { construct(this, &descriptor); }
    ~Static974e0() { destroy(this); }
};
