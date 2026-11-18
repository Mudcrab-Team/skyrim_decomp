// Source exposure: binary-analysis; no external implementation source reused.
// Static176cb40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176cb40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176cb40*);
    virtual void release(Static176cb40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176cb40*);
struct Static176cb40 {
    void* value;
    Static176cb40();
    ~Static176cb40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
