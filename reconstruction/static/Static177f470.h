// Source exposure: binary-analysis; no external implementation source reused.
// Static177f470, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f470;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f470*);
    virtual void release(Static177f470*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f470*);
struct Static177f470 {
    void* value;
    Static177f470();
    ~Static177f470() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
