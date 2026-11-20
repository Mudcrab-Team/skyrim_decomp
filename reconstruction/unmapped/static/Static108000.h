// Source exposure: binary-analysis
// Static108000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108000;
extern void construct(Static108000*, const Descriptor*);
extern void destroy(Static108000*);
struct Static108000 {
    void* value;
    Static108000() { construct(this, &descriptor); }
    ~Static108000() { destroy(this); }
};
