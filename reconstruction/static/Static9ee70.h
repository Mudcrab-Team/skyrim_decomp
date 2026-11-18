// Source exposure: binary-analysis
// Static9ee70, Descriptor, descriptor, construct, destroy, object: GUESS(low) STANDIN
#pragma once
struct Descriptor;
extern Descriptor descriptor;
struct Static9ee70;
extern void construct(Static9ee70*, const Descriptor*);
extern void destroy(Static9ee70*);
struct Static9ee70 {
    void* value;
    Static9ee70() { construct(this, &descriptor); }
    ~Static9ee70() { destroy(this); }
};
