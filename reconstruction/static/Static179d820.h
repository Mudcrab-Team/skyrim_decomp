// Source exposure: binary-analysis; no external implementation source reused.
// Static179d820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d820*);
    virtual void release(Static179d820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d820*);
struct Static179d820 {
    void* value;
    Static179d820();
    ~Static179d820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
