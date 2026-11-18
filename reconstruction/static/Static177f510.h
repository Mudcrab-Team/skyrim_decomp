// Source exposure: binary-analysis; no external implementation source reused.
// Static177f510, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f510;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f510*);
    virtual void release(Static177f510*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f510*);
struct Static177f510 {
    void* value;
    Static177f510();
    ~Static177f510() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
