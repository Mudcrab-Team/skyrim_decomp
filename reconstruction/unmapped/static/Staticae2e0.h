// Source exposure: binary-analysis
// Staticae2e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticae2e0;
extern void construct(Staticae2e0*, const Descriptor*);
extern void destroy(Staticae2e0*);
struct Staticae2e0 {
    void* value;
    Staticae2e0() { construct(this, &descriptor); }
    ~Staticae2e0() { destroy(this); }
};
