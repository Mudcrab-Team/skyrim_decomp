// Source exposure: binary-analysis; no external implementation source reused.
// Static17aac50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aac50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aac50*);
    virtual void release(Static17aac50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aac50*);
struct Static17aac50 {
    void* value;
    Static17aac50();
    ~Static17aac50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
