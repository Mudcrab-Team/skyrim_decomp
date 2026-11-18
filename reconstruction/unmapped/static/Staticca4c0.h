// Source exposure: binary-analysis
// Staticca4c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca4c0;
extern void construct(Staticca4c0*, const Descriptor*);
extern void destroy(Staticca4c0*);
struct Staticca4c0 {
    void* value;
    Staticca4c0() { construct(this, &descriptor); }
    ~Staticca4c0() { destroy(this); }
};
