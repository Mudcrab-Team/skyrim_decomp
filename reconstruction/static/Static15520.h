// Source exposure: binary-analysis
// Static15520, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static15520;
extern void construct(Static15520*, const Descriptor*);
extern void destroy(Static15520*);
struct Static15520 {
    void* value;
    Static15520() { construct(this, &descriptor); }
    ~Static15520() { destroy(this); }
};
