// Source exposure: binary-analysis
// Staticcab00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticcab00;
extern void construct(Staticcab00*, const Descriptor*);
extern void destroy(Staticcab00*);
struct Staticcab00 {
    void* value;
    Staticcab00() { construct(this, &descriptor); }
    ~Staticcab00() { destroy(this); }
};
