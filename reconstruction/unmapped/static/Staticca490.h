// Source exposure: binary-analysis
// Staticca490, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Staticca490;
extern void construct(Staticca490*, const Descriptor*);
extern void destroy(Staticca490*);
struct Staticca490 {
    void* value;
    Staticca490() { construct(this, &descriptor); }
    ~Staticca490() { destroy(this); }
};
