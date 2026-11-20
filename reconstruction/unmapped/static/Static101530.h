// Source exposure: binary-analysis
// Static101530, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101530;
extern void construct(Static101530*, const Descriptor*);
extern void destroy(Static101530*);
struct Static101530 {
    void* value;
    Static101530() { construct(this, &descriptor); }
    ~Static101530() { destroy(this); }
};
