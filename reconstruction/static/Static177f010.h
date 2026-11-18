// Source exposure: binary-analysis; no external implementation source reused.
// Static177f010, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f010;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f010*);
    virtual void release(Static177f010*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f010*);
struct Static177f010 {
    void* value;
    Static177f010();
    ~Static177f010() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
