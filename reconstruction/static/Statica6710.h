// Source exposure: binary-analysis
// Statica6710, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6710;
extern void construct(Statica6710*, const Descriptor*);
extern void destroy(Statica6710*);
struct Statica6710 {
    void* value;
    Statica6710() { construct(this, &descriptor); }
    ~Statica6710() { destroy(this); }
};
