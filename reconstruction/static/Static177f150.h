// Source exposure: binary-analysis; no external implementation source reused.
// Static177f150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f150*);
    virtual void release(Static177f150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f150*);
struct Static177f150 {
    void* value;
    Static177f150();
    ~Static177f150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
