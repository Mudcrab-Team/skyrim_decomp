// Source exposure: binary-analysis
// Statica63e0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica63e0;
extern void construct(Statica63e0*, const Descriptor*);
extern void destroy(Statica63e0*);
struct Statica63e0 {
    void* value;
    Statica63e0() { construct(this, &descriptor); }
    ~Statica63e0() { destroy(this); }
};
