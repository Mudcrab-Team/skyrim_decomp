// Source exposure: binary-analysis; no external implementation source reused.
// Static177cb80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177cb80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177cb80*);
    virtual void release(Static177cb80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177cb80*);
struct Static177cb80 {
    void* value;
    Static177cb80();
    ~Static177cb80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
