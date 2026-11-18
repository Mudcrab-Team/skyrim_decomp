// Source exposure: binary-analysis
// Staticca1f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca1f0;
extern void construct(Staticca1f0*, const Descriptor*);
extern void destroy(Staticca1f0*);
struct Staticca1f0 {
    void* value;
    Staticca1f0() { construct(this, &descriptor); }
    ~Staticca1f0() { destroy(this); }
};
