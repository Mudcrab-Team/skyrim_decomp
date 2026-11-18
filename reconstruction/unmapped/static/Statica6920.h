// Source exposure: binary-analysis
// Statica6920, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6920;
extern void construct(Statica6920*, const Descriptor*);
extern void destroy(Statica6920*);
struct Statica6920 {
    void* value;
    Statica6920() { construct(this, &descriptor); }
    ~Statica6920() { destroy(this); }
};
