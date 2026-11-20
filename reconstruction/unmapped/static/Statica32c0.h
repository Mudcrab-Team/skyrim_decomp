// Source exposure: binary-analysis
// Statica32c0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica32c0;
extern void construct(Statica32c0*, const Descriptor*);
extern void destroy(Statica32c0*);
struct Statica32c0 {
    void* value;
    Statica32c0() { construct(this, &descriptor); }
    ~Statica32c0() { destroy(this); }
};
