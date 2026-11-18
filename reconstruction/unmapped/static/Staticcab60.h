// Source exposure: binary-analysis
// Staticcab60, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcab60;
extern void construct(Staticcab60*, const Descriptor*);
extern void destroy(Staticcab60*);
struct Staticcab60 {
    void* value;
    Staticcab60() { construct(this, &descriptor); }
    ~Staticcab60() { destroy(this); }
};
