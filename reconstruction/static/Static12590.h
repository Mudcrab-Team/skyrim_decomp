// Source exposure: binary-analysis
// Static12590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static12590;
extern void construct(Static12590*, const Descriptor*);
extern void destroy(Static12590*);
struct Static12590 {
    void* value;
    Static12590() { construct(this, &descriptor); }
    ~Static12590() { destroy(this); }
};
