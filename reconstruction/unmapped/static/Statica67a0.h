// Source exposure: binary-analysis
// Statica67a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica67a0;
extern void construct(Statica67a0*, const Descriptor*);
extern void destroy(Statica67a0*);
struct Statica67a0 {
    void* value;
    Statica67a0() { construct(this, &descriptor); }
    ~Statica67a0() { destroy(this); }
};
