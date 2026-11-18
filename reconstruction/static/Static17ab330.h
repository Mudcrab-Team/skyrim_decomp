// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab330, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab330;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab330*);
    virtual void release(Static17ab330*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab330*);
struct Static17ab330 {
    void* value;
    Static17ab330();
    ~Static17ab330() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
