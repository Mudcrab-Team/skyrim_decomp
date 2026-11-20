// Source exposure: binary-analysis
// Statica2e40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2e40;
extern void construct(Statica2e40*, const Descriptor*);
extern void destroy(Statica2e40*);
struct Statica2e40 {
    void* value;
    Statica2e40() { construct(this, &descriptor); }
    ~Statica2e40() { destroy(this); }
};
