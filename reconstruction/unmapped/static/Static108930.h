// Source exposure: binary-analysis
// Static108930, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108930;
extern void construct(Static108930*, const Descriptor*);
extern void destroy(Static108930*);
struct Static108930 {
    void* value;
    Static108930() { construct(this, &descriptor); }
    ~Static108930() { destroy(this); }
};
