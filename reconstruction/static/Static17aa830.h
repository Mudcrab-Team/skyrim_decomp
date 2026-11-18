// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa830*);
    virtual void release(Static17aa830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa830*);
struct Static17aa830 {
    void* value;
    Static17aa830();
    ~Static17aa830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
