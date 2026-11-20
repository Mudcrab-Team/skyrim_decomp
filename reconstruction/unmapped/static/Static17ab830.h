// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab830*);
    virtual void release(Static17ab830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab830*);
struct Static17ab830 {
    void* value;
    Static17ab830();
    ~Static17ab830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
