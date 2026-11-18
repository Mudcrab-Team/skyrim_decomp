// Source exposure: binary-analysis
// Staticb5490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticb5490;
extern void construct(Staticb5490*, const Descriptor*);
extern void destroy(Staticb5490*);
struct Staticb5490 {
    void* value;
    Staticb5490() { construct(this, &descriptor); }
    ~Staticb5490() { destroy(this); }
};
