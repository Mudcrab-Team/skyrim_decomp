// Source exposure: binary-analysis
// Staticbaec0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbaec0;
extern void construct(Staticbaec0*, const Descriptor*);
extern void destroy(Staticbaec0*);
struct Staticbaec0 {
    void* value;
    Staticbaec0() { construct(this, &descriptor); }
    ~Staticbaec0() { destroy(this); }
};
