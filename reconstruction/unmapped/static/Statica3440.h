// Source exposure: binary-analysis
// Statica3440, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica3440;
extern void construct(Statica3440*, const Descriptor*);
extern void destroy(Statica3440*);
struct Statica3440 {
    void* value;
    Statica3440() { construct(this, &descriptor); }
    ~Statica3440() { destroy(this); }
};
