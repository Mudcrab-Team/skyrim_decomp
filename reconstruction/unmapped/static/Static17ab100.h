// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab100*);
    virtual void release(Static17ab100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab100*);
struct Static17ab100 {
    void* value;
    Static17ab100();
    ~Static17ab100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
