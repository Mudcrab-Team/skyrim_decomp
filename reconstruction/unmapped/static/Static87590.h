// Source exposure: binary-analysis
// Static87590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static87590;
extern void construct(Static87590*, const Descriptor*);
extern void destroy(Static87590*);
struct Static87590 {
    void* value;
    Static87590() { construct(this, &descriptor); }
    ~Static87590() { destroy(this); }
};
