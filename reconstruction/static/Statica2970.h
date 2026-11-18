// Source exposure: binary-analysis
// Statica2970, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2970;
extern void construct(Statica2970*, const Descriptor*);
extern void destroy(Statica2970*);
struct Statica2970 {
    void* value;
    Statica2970() { construct(this, &descriptor); }
    ~Statica2970() { destroy(this); }
};
