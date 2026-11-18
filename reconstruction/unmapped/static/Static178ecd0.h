// Source exposure: binary-analysis; no external implementation source reused.
// Static178ecd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ecd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ecd0*);
    virtual void release(Static178ecd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ecd0*);
struct Static178ecd0 {
    void* value;
    Static178ecd0();
    ~Static178ecd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
