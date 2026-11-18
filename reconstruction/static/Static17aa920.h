// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa920*);
    virtual void release(Static17aa920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa920*);
struct Static17aa920 {
    void* value;
    Static17aa920();
    ~Static17aa920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
