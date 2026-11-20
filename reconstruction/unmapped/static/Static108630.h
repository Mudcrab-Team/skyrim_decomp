// Source exposure: binary-analysis
// Static108630, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static108630;
extern void construct(Static108630*, const Descriptor*);
extern void destroy(Static108630*);
struct Static108630 {
    void* value;
    Static108630() { construct(this, &descriptor); }
    ~Static108630() { destroy(this); }
};
