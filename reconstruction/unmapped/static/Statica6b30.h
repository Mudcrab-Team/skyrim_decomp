// Source exposure: binary-analysis
// Statica6b30, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6b30;
extern void construct(Statica6b30*, const Descriptor*);
extern void destroy(Statica6b30*);
struct Statica6b30 {
    void* value;
    Statica6b30() { construct(this, &descriptor); }
    ~Statica6b30() { destroy(this); }
};
