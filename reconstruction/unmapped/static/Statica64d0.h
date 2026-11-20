// Source exposure: binary-analysis
// Statica64d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica64d0;
extern void construct(Statica64d0*, const Descriptor*);
extern void destroy(Statica64d0*);
struct Statica64d0 {
    void* value;
    Statica64d0() { construct(this, &descriptor); }
    ~Statica64d0() { destroy(this); }
};
