// Source exposure: binary-analysis
// Static9f520, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f520;
extern void construct(Static9f520*, const Descriptor*);
extern void destroy(Static9f520*);
struct Static9f520 {
    void* value;
    Static9f520() { construct(this, &descriptor); }
    ~Static9f520() { destroy(this); }
};
