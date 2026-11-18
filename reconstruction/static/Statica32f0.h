// Source exposure: binary-analysis
// Statica32f0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica32f0;
extern void construct(Statica32f0*, const Descriptor*);
extern void destroy(Statica32f0*);
struct Statica32f0 {
    void* value;
    Statica32f0() { construct(this, &descriptor); }
    ~Statica32f0() { destroy(this); }
};
