// Source exposure: binary-analysis; no external implementation source reused.
// Static173dd30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173dd30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173dd30*);
    virtual void release(Static173dd30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173dd30*);
struct Static173dd30 {
    void* value;
    Static173dd30();
    ~Static173dd30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
