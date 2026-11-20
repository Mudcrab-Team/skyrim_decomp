// Source exposure: binary-analysis
// Staticc1b00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc1b00;
extern void construct(Staticc1b00*, const Descriptor*);
extern void destroy(Staticc1b00*);
struct Staticc1b00 {
    void* value;
    Staticc1b00() { construct(this, &descriptor); }
    ~Staticc1b00() { destroy(this); }
};
