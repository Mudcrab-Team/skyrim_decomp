// Source exposure: binary-analysis
// Statica2880, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2880;
extern void construct(Statica2880*, const Descriptor*);
extern void destroy(Statica2880*);
struct Statica2880 {
    void* value;
    Statica2880() { construct(this, &descriptor); }
    ~Statica2880() { destroy(this); }
};
