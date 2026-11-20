// Source exposure: binary-analysis
// Static108480, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108480;
extern void construct(Static108480*, const Descriptor*);
extern void destroy(Static108480*);
struct Static108480 {
    void* value;
    Static108480() { construct(this, &descriptor); }
    ~Static108480() { destroy(this); }
};
