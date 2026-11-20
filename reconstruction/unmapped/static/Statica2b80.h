// Source exposure: binary-analysis
// Statica2b80, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2b80;
extern void construct(Statica2b80*, const Descriptor*);
extern void destroy(Statica2b80*);
struct Statica2b80 {
    void* value;
    Statica2b80() { construct(this, &descriptor); }
    ~Statica2b80() { destroy(this); }
};
