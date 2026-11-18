// Source exposure: binary-analysis
// Staticf5390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticf5390;
extern void construct(Staticf5390*, const Descriptor*);
extern void destroy(Staticf5390*);
struct Staticf5390 {
    void* value;
    Staticf5390() { construct(this, &descriptor); }
    ~Staticf5390() { destroy(this); }
};
