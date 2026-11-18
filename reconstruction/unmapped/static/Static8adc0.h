// Source exposure: binary-analysis
// Static8adc0, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static8adc0;
extern void construct(Static8adc0*, const Descriptor*);
extern void destroy(Static8adc0*);
struct Static8adc0 {
    void* value;
    Static8adc0() { construct(this, &descriptor); }
    ~Static8adc0() { destroy(this); }
};
