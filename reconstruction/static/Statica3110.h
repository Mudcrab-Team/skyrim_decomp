// Source exposure: binary-analysis
// Statica3110, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3110;
extern void construct(Statica3110*, const Descriptor*);
extern void destroy(Statica3110*);
struct Statica3110 {
    void* value;
    Statica3110() { construct(this, &descriptor); }
    ~Statica3110() { destroy(this); }
};
