// Source exposure: binary-analysis
// Staticea530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticea530;
extern void construct(Staticea530*, const Descriptor*);
extern void destroy(Staticea530*);
struct Staticea530 {
    void* value;
    Staticea530() { construct(this, &descriptor); }
    ~Staticea530() { destroy(this); }
};
