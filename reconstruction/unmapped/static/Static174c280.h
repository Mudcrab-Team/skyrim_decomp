// Source exposure: binary-analysis; no external implementation source reused.
// Static174c280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c280*);
    virtual void release(Static174c280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c280*);
struct Static174c280 {
    void* value;
    Static174c280();
    ~Static174c280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
