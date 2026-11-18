// Source exposure: binary-analysis
// Staticca2e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca2e0;
extern void construct(Staticca2e0*, const Descriptor*);
extern void destroy(Staticca2e0*);
struct Staticca2e0 {
    void* value;
    Staticca2e0() { construct(this, &descriptor); }
    ~Staticca2e0() { destroy(this); }
};
