// Source exposure: binary-analysis; no external implementation source reused.
// Static176ff70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176ff70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176ff70*);
    virtual void release(Static176ff70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176ff70*);
struct Static176ff70 {
    void* value;
    Static176ff70();
    ~Static176ff70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
