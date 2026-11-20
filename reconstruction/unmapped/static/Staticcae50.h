// Source exposure: binary-analysis
// Staticcae50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcae50;
extern void construct(Staticcae50*, const Descriptor*);
extern void destroy(Staticcae50*);
struct Staticcae50 {
    void* value;
    Staticcae50() { construct(this, &descriptor); }
    ~Staticcae50() { destroy(this); }
};
