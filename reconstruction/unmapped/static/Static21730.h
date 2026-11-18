// Source exposure: binary-analysis
// Static21730, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static21730;
extern void construct(Static21730*, const Descriptor*);
extern void destroy(Static21730*);
struct Static21730 {
    void* value;
    Static21730() { construct(this, &descriptor); }
    ~Static21730() { destroy(this); }
};
