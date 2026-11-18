// Source exposure: binary-analysis; no external implementation source reused.
// Static177f330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f330*);
    virtual void release(Static177f330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f330*);
struct Static177f330 {
    void* value;
    Static177f330();
    ~Static177f330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
