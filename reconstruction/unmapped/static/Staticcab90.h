// Source exposure: binary-analysis
// Staticcab90, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcab90;
extern void construct(Staticcab90*, const Descriptor*);
extern void destroy(Staticcab90*);
struct Staticcab90 {
    void* value;
    Staticcab90() { construct(this, &descriptor); }
    ~Staticcab90() { destroy(this); }
};
