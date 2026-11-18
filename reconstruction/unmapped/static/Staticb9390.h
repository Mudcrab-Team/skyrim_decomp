// Source exposure: binary-analysis
// Staticb9390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb9390;
extern void construct(Staticb9390*, const Descriptor*);
extern void destroy(Staticb9390*);
struct Staticb9390 {
    void* value;
    Staticb9390() { construct(this, &descriptor); }
    ~Staticb9390() { destroy(this); }
};
