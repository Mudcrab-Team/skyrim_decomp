// Source exposure: binary-analysis
// Statica34a0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica34a0;
extern void construct(Statica34a0*, const Descriptor*);
extern void destroy(Statica34a0*);
struct Statica34a0 {
    void* value;
    Statica34a0() { construct(this, &descriptor); }
    ~Statica34a0() { destroy(this); }
};
