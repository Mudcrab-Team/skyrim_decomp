// Source exposure: binary-analysis; no external implementation source reused.
// Static177f600, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f600;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f600*);
    virtual void release(Static177f600*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f600*);
struct Static177f600 {
    void* value;
    Static177f600();
    ~Static177f600() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
