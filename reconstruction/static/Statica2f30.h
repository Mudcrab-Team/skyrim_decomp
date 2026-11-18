// Source exposure: binary-analysis
// Statica2f30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2f30;
extern void construct(Statica2f30*, const Descriptor*);
extern void destroy(Statica2f30*);
struct Statica2f30 {
    void* value;
    Statica2f30() { construct(this, &descriptor); }
    ~Statica2f30() { destroy(this); }
};
