// Source exposure: binary-analysis
// Statica3590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3590;
extern void construct(Statica3590*, const Descriptor*);
extern void destroy(Statica3590*);
struct Statica3590 {
    void* value;
    Statica3590() { construct(this, &descriptor); }
    ~Statica3590() { destroy(this); }
};
