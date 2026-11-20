// Source exposure: binary-analysis
// Statica2c70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica2c70;
extern void construct(Statica2c70*, const Descriptor*);
extern void destroy(Statica2c70*);
struct Statica2c70 {
    void* value;
    Statica2c70() { construct(this, &descriptor); }
    ~Statica2c70() { destroy(this); }
};
