// Source exposure: binary-analysis
// Staticbd390, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbd390;
extern void construct(Staticbd390*, const Descriptor*);
extern void destroy(Staticbd390*);
struct Staticbd390 {
    void* value;
    Staticbd390() { construct(this, &descriptor); }
    ~Staticbd390() { destroy(this); }
};
