// Source exposure: binary-analysis
// Staticc3250, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticc3250;
extern void construct(Staticc3250*, const Descriptor*);
extern void destroy(Staticc3250*);
struct Staticc3250 {
    void* value;
    Staticc3250() { construct(this, &descriptor); }
    ~Staticc3250() { destroy(this); }
};
