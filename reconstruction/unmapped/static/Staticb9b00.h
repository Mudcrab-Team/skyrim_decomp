// Source exposure: binary-analysis
// Staticb9b00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9b00;
extern void construct(Staticb9b00*, const Descriptor*);
extern void destroy(Staticb9b00*);
struct Staticb9b00 {
    void* value;
    Staticb9b00() { construct(this, &descriptor); }
    ~Staticb9b00() { destroy(this); }
};
