// Source exposure: binary-analysis
// Static101590, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101590;
extern void construct(Static101590*, const Descriptor*);
extern void destroy(Static101590*);
struct Static101590 {
    void* value;
    Static101590() { construct(this, &descriptor); }
    ~Static101590() { destroy(this); }
};
