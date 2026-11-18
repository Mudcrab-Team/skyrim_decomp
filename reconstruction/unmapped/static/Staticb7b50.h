// Source exposure: binary-analysis
// Staticb7b50, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb7b50;
extern void construct(Staticb7b50*, const Descriptor*);
extern void destroy(Staticb7b50*);
struct Staticb7b50 {
    void* value;
    Staticb7b50() { construct(this, &descriptor); }
    ~Staticb7b50() { destroy(this); }
};
