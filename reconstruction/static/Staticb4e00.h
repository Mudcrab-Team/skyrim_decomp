// Source exposure: binary-analysis
// Staticb4e00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb4e00;
extern void construct(Staticb4e00*, const Descriptor*);
extern void destroy(Staticb4e00*);
struct Staticb4e00 {
    void* value;
    Staticb4e00() { construct(this, &descriptor); }
    ~Staticb4e00() { destroy(this); }
};
