// Source exposure: binary-analysis
// Static101200, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static101200;
extern void construct(Static101200*, const Descriptor*);
extern void destroy(Static101200*);
struct Static101200 {
    void* value;
    Static101200() { construct(this, &descriptor); }
    ~Static101200() { destroy(this); }
};
