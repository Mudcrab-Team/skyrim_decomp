// Source exposure: binary-analysis
// Statica2f60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2f60;
extern void construct(Statica2f60*, const Descriptor*);
extern void destroy(Statica2f60*);
struct Statica2f60 {
    void* value;
    Statica2f60() { construct(this, &descriptor); }
    ~Statica2f60() { destroy(this); }
};
