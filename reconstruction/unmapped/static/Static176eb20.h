// Source exposure: binary-analysis; no external implementation source reused.
// Static176eb20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176eb20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176eb20*);
    virtual void release(Static176eb20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176eb20*);
struct Static176eb20 {
    void* value;
    Static176eb20();
    ~Static176eb20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
