// Source exposure: binary-analysis
// Static90000, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static90000;
extern void construct(Static90000*, const Descriptor*);
extern void destroy(Static90000*);
struct Static90000 {
    void* value;
    Static90000() { construct(this, &descriptor); }
    ~Static90000() { destroy(this); }
};
