// Source exposure: binary-analysis; no external implementation source reused.
// Static177c040, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c040;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c040*);
    virtual void release(Static177c040*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c040*);
struct Static177c040 {
    void* value;
    Static177c040();
    ~Static177c040() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
