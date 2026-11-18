// Source exposure: binary-analysis
// Static101020, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101020;
extern void construct(Static101020*, const Descriptor*);
extern void destroy(Static101020*);
struct Static101020 {
    void* value;
    Static101020() { construct(this, &descriptor); }
    ~Static101020() { destroy(this); }
};
