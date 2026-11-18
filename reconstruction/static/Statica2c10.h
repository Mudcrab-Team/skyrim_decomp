// Source exposure: binary-analysis
// Statica2c10, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2c10;
extern void construct(Statica2c10*, const Descriptor*);
extern void destroy(Statica2c10*);
struct Statica2c10 {
    void* value;
    Statica2c10() { construct(this, &descriptor); }
    ~Statica2c10() { destroy(this); }
};
