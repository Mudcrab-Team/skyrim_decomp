// Source exposure: binary-analysis
// Staticca3a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca3a0;
extern void construct(Staticca3a0*, const Descriptor*);
extern void destroy(Staticca3a0*);
struct Staticca3a0 {
    void* value;
    Staticca3a0() { construct(this, &descriptor); }
    ~Staticca3a0() { destroy(this); }
};
