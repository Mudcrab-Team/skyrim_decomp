// Source exposure: binary-analysis; no external implementation source reused.
// Static17c0e50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c0e50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c0e50*);
    virtual void release(Static17c0e50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c0e50*);
struct Static17c0e50 {
    void* value;
    Static17c0e50();
    ~Static17c0e50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
