// Source exposure: binary-analysis
// Staticca2b0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca2b0;
extern void construct(Staticca2b0*, const Descriptor*);
extern void destroy(Staticca2b0*);
struct Staticca2b0 {
    void* value;
    Staticca2b0() { construct(this, &descriptor); }
    ~Staticca2b0() { destroy(this); }
};
