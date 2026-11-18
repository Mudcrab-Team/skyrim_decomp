// Source exposure: binary-analysis
// Statica33e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica33e0;
extern void construct(Statica33e0*, const Descriptor*);
extern void destroy(Statica33e0*);
struct Statica33e0 {
    void* value;
    Statica33e0() { construct(this, &descriptor); }
    ~Statica33e0() { destroy(this); }
};
