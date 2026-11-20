// Source exposure: binary-analysis
// Statica37d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica37d0;
extern void construct(Statica37d0*, const Descriptor*);
extern void destroy(Statica37d0*);
struct Statica37d0 {
    void* value;
    Statica37d0() { construct(this, &descriptor); }
    ~Statica37d0() { destroy(this); }
};
