// Source exposure: binary-analysis
// Staticb5850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5850;
extern void construct(Staticb5850*, const Descriptor*);
extern void destroy(Staticb5850*);
struct Staticb5850 {
    void* value;
    Staticb5850() { construct(this, &descriptor); }
    ~Staticb5850() { destroy(this); }
};
