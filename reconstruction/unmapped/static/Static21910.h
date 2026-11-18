// Source exposure: binary-analysis
// Static21910, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21910;
extern void construct(Static21910*, const Descriptor*);
extern void destroy(Static21910*);
struct Static21910 {
    void* value;
    Static21910() { construct(this, &descriptor); }
    ~Static21910() { destroy(this); }
};
