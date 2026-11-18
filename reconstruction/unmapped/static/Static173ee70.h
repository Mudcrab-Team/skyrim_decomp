// Source exposure: binary-analysis; no external implementation source reused.
// Static173ee70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173ee70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173ee70*);
    virtual void release(Static173ee70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173ee70*);
struct Static173ee70 {
    void* value;
    Static173ee70();
    ~Static173ee70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
