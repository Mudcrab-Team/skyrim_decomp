// Source exposure: binary-analysis
// Statica7bc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica7bc0;
extern void construct(Statica7bc0*, const Descriptor*);
extern void destroy(Statica7bc0*);
struct Statica7bc0 {
    void* value;
    Statica7bc0() { construct(this, &descriptor); }
    ~Statica7bc0() { destroy(this); }
};
