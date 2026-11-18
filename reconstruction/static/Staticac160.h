// Source exposure: binary-analysis
// Staticac160, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticac160;
extern void construct(Staticac160*, const Descriptor*);
extern void destroy(Staticac160*);
struct Staticac160 {
    void* value;
    Staticac160() { construct(this, &descriptor); }
    ~Staticac160() { destroy(this); }
};
