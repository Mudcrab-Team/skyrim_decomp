// Source exposure: binary-analysis
// Statica98f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica98f0;
extern void construct(Statica98f0*, const Descriptor*);
extern void destroy(Statica98f0*);
struct Statica98f0 {
    void* value;
    Statica98f0() { construct(this, &descriptor); }
    ~Statica98f0() { destroy(this); }
};
