// Source exposure: binary-analysis
// Static9f730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9f730;
extern void construct(Static9f730*, const Descriptor*);
extern void destroy(Static9f730*);
struct Static9f730 {
    void* value;
    Static9f730() { construct(this, &descriptor); }
    ~Static9f730() { destroy(this); }
};
