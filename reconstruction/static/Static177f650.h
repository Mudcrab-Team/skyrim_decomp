// Source exposure: binary-analysis; no external implementation source reused.
// Static177f650, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f650;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f650*);
    virtual void release(Static177f650*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f650*);
struct Static177f650 {
    void* value;
    Static177f650();
    ~Static177f650() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
