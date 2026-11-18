// Source exposure: binary-analysis; no external implementation source reused.
// Static179f030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179f030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179f030*);
    virtual void release(Static179f030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179f030*);
struct Static179f030 {
    void* value;
    Static179f030();
    ~Static179f030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
