// Source exposure: binary-analysis
// Statica3170, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3170;
extern void construct(Statica3170*, const Descriptor*);
extern void destroy(Statica3170*);
struct Statica3170 {
    void* value;
    Statica3170() { construct(this, &descriptor); }
    ~Statica3170() { destroy(this); }
};
