// Source exposure: binary-analysis
// Statica3500, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3500;
extern void construct(Statica3500*, const Descriptor*);
extern void destroy(Statica3500*);
struct Statica3500 {
    void* value;
    Statica3500() { construct(this, &descriptor); }
    ~Statica3500() { destroy(this); }
};
