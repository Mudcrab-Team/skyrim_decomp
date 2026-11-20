// Source exposure: binary-analysis
// Statica4590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica4590;
extern void construct(Statica4590*, const Descriptor*);
extern void destroy(Statica4590*);
struct Statica4590 {
    void* value;
    Statica4590() { construct(this, &descriptor); }
    ~Statica4590() { destroy(this); }
};
