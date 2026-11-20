// Source exposure: binary-analysis
// Staticca4f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca4f0;
extern void construct(Staticca4f0*, const Descriptor*);
extern void destroy(Staticca4f0*);
struct Staticca4f0 {
    void* value;
    Staticca4f0() { construct(this, &descriptor); }
    ~Staticca4f0() { destroy(this); }
};
