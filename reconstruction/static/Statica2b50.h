// Source exposure: binary-analysis
// Statica2b50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2b50;
extern void construct(Statica2b50*, const Descriptor*);
extern void destroy(Statica2b50*);
struct Statica2b50 {
    void* value;
    Statica2b50() { construct(this, &descriptor); }
    ~Statica2b50() { destroy(this); }
};
