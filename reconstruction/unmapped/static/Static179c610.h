// Source exposure: binary-analysis; no external implementation source reused.
// Static179c610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c610*);
    virtual void release(Static179c610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c610*);
struct Static179c610 {
    void* value;
    Static179c610();
    ~Static179c610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
