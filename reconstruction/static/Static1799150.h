// Source exposure: binary-analysis; no external implementation source reused.
// Static1799150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799150*);
    virtual void release(Static1799150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799150*);
struct Static1799150 {
    void* value;
    Static1799150();
    ~Static1799150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
