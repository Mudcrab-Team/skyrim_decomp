// Source exposure: binary-analysis
// Statica6530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica6530;
extern void construct(Statica6530*, const Descriptor*);
extern void destroy(Statica6530*);
struct Statica6530 {
    void* value;
    Statica6530() { construct(this, &descriptor); }
    ~Statica6530() { destroy(this); }
};
