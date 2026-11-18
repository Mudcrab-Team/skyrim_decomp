// Source exposure: binary-analysis; no external implementation source reused.
// Static176eb70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176eb70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176eb70*);
    virtual void release(Static176eb70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176eb70*);
struct Static176eb70 {
    void* value;
    Static176eb70();
    ~Static176eb70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
