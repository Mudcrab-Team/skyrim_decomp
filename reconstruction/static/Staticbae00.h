// Source exposure: binary-analysis
// Staticbae00, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticbae00;
extern void construct(Staticbae00*, const Descriptor*);
extern void destroy(Staticbae00*);
struct Staticbae00 {
    void* value;
    Staticbae00() { construct(this, &descriptor); }
    ~Staticbae00() { destroy(this); }
};
