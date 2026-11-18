// Source exposure: binary-analysis; no external implementation source reused.
// Static176cd20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cd20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cd20*);
    virtual void release(Static176cd20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cd20*);
struct Static176cd20 {
    void* value;
    Static176cd20();
    ~Static176cd20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
