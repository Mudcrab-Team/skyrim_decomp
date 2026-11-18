// Source exposure: binary-analysis; no external implementation source reused.
// Static17c0f40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17c0f40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17c0f40*);
    virtual void release(Static17c0f40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17c0f40*);
struct Static17c0f40 {
    void* value;
    Static17c0f40();
    ~Static17c0f40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
