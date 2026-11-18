// Source exposure: binary-analysis
// Statica2de0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2de0;
extern void construct(Statica2de0*, const Descriptor*);
extern void destroy(Statica2de0*);
struct Statica2de0 {
    void* value;
    Statica2de0() { construct(this, &descriptor); }
    ~Statica2de0() { destroy(this); }
};
