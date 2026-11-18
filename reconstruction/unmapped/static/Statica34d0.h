// Source exposure: binary-analysis
// Statica34d0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica34d0;
extern void construct(Statica34d0*, const Descriptor*);
extern void destroy(Statica34d0*);
struct Statica34d0 {
    void* value;
    Statica34d0() { construct(this, &descriptor); }
    ~Statica34d0() { destroy(this); }
};
