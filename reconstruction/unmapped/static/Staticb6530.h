// Source exposure: binary-analysis
// Staticb6530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb6530;
extern void construct(Staticb6530*, const Descriptor*);
extern void destroy(Staticb6530*);
struct Staticb6530 {
    void* value;
    Staticb6530() { construct(this, &descriptor); }
    ~Staticb6530() { destroy(this); }
};
