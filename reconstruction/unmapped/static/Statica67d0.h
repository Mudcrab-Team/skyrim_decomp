// Source exposure: binary-analysis
// Statica67d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica67d0;
extern void construct(Statica67d0*, const Descriptor*);
extern void destroy(Statica67d0*);
struct Statica67d0 {
    void* value;
    Statica67d0() { construct(this, &descriptor); }
    ~Statica67d0() { destroy(this); }
};
