// Source exposure: binary-analysis
// Staticb5520, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5520;
extern void construct(Staticb5520*, const Descriptor*);
extern void destroy(Staticb5520*);
struct Staticb5520 {
    void* value;
    Staticb5520() { construct(this, &descriptor); }
    ~Staticb5520() { destroy(this); }
};
