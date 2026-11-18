// Source exposure: binary-analysis; no external implementation source reused.
// Static174c190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c190*);
    virtual void release(Static174c190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c190*);
struct Static174c190 {
    void* value;
    Static174c190();
    ~Static174c190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
