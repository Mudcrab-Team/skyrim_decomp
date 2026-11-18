// Source exposure: binary-analysis
// Statica37a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica37a0;
extern void construct(Statica37a0*, const Descriptor*);
extern void destroy(Statica37a0*);
struct Statica37a0 {
    void* value;
    Statica37a0() { construct(this, &descriptor); }
    ~Statica37a0() { destroy(this); }
};
