// Source exposure: binary-analysis
// Static16230, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static16230;
extern void construct(Static16230*, const Descriptor*);
extern void destroy(Static16230*);
struct Static16230 {
    void* value;
    Static16230() { construct(this, &descriptor); }
    ~Static16230() { destroy(this); }
};
