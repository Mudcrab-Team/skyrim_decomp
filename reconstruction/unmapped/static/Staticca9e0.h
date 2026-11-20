// Source exposure: binary-analysis
// Staticca9e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca9e0;
extern void construct(Staticca9e0*, const Descriptor*);
extern void destroy(Staticca9e0*);
struct Staticca9e0 {
    void* value;
    Staticca9e0() { construct(this, &descriptor); }
    ~Staticca9e0() { destroy(this); }
};
