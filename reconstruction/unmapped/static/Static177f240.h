// Source exposure: binary-analysis; no external implementation source reused.
// Static177f240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f240*);
    virtual void release(Static177f240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f240*);
struct Static177f240 {
    void* value;
    Static177f240();
    ~Static177f240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
