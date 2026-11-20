// Source exposure: binary-analysis
// Staticefa00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticefa00;
extern void construct(Staticefa00*, const Descriptor*);
extern void destroy(Staticefa00*);
struct Staticefa00 {
    void* value;
    Staticefa00() { construct(this, &descriptor); }
    ~Staticefa00() { destroy(this); }
};
