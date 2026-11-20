// Source exposure: binary-analysis
// Statica6620, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6620;
extern void construct(Statica6620*, const Descriptor*);
extern void destroy(Statica6620*);
struct Statica6620 {
    void* value;
    Statica6620() { construct(this, &descriptor); }
    ~Statica6620() { destroy(this); }
};
