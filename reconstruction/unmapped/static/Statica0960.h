// Source exposure: binary-analysis
// Statica0960, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Statica0960;
extern void construct(Statica0960*, const Descriptor*);
extern void destroy(Statica0960*);
struct Statica0960 {
    void* value;
    Statica0960() { construct(this, &descriptor); }
    ~Statica0960() { destroy(this); }
};
