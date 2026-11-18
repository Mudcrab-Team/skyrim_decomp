// Source exposure: binary-analysis
// Statica2a30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2a30;
extern void construct(Statica2a30*, const Descriptor*);
extern void destroy(Statica2a30*);
struct Statica2a30 {
    void* value;
    Statica2a30() { construct(this, &descriptor); }
    ~Statica2a30() { destroy(this); }
};
