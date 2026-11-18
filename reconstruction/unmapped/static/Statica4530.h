// Source exposure: binary-analysis
// Statica4530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica4530;
extern void construct(Statica4530*, const Descriptor*);
extern void destroy(Statica4530*);
struct Statica4530 {
    void* value;
    Statica4530() { construct(this, &descriptor); }
    ~Statica4530() { destroy(this); }
};
