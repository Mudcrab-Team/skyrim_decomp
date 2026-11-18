// Source exposure: binary-analysis
// Staticb9570, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9570;
extern void construct(Staticb9570*, const Descriptor*);
extern void destroy(Staticb9570*);
struct Staticb9570 {
    void* value;
    Staticb9570() { construct(this, &descriptor); }
    ~Staticb9570() { destroy(this); }
};
