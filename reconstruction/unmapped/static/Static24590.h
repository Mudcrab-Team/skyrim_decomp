// Source exposure: binary-analysis
// Static24590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static24590;
extern void construct(Static24590*, const Descriptor*);
extern void destroy(Static24590*);
struct Static24590 {
    void* value;
    Static24590() { construct(this, &descriptor); }
    ~Static24590() { destroy(this); }
};
