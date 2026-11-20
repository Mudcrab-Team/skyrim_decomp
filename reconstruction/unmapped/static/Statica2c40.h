// Source exposure: binary-analysis
// Statica2c40, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2c40;
extern void construct(Statica2c40*, const Descriptor*);
extern void destroy(Statica2c40*);
struct Statica2c40 {
    void* value;
    Statica2c40() { construct(this, &descriptor); }
    ~Statica2c40() { destroy(this); }
};
