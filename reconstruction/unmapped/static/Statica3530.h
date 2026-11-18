// Source exposure: binary-analysis
// Statica3530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3530;
extern void construct(Statica3530*, const Descriptor*);
extern void destroy(Statica3530*);
struct Statica3530 {
    void* value;
    Statica3530() { construct(this, &descriptor); }
    ~Statica3530() { destroy(this); }
};
