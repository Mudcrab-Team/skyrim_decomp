// Source exposure: binary-analysis; no external implementation source reused.
// Static176fe30, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176fe30;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176fe30*);
    virtual void release(Static176fe30*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176fe30*);
struct Static176fe30 {
    void* value;
    Static176fe30();
    ~Static176fe30() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
