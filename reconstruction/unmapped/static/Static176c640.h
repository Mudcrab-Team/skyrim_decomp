// Source exposure: binary-analysis; no external implementation source reused.
// Static176c640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176c640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176c640*);
    virtual void release(Static176c640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176c640*);
struct Static176c640 {
    void* value;
    Static176c640();
    ~Static176c640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
