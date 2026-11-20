// Source exposure: binary-analysis
// Static108300, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108300;
extern void construct(Static108300*, const Descriptor*);
extern void destroy(Static108300*);
struct Static108300 {
    void* value;
    Static108300() { construct(this, &descriptor); }
    ~Static108300() { destroy(this); }
};
