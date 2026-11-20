// Source exposure: binary-analysis
// Static15850, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15850;
extern void construct(Static15850*, const Descriptor*);
extern void destroy(Static15850*);
struct Static15850 {
    void* value;
    Static15850() { construct(this, &descriptor); }
    ~Static15850() { destroy(this); }
};
