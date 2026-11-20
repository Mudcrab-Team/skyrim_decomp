// Source exposure: binary-analysis; no external implementation source reused.
// Static179d730, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d730;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d730*);
    virtual void release(Static179d730*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d730*);
struct Static179d730 {
    void* value;
    Static179d730();
    ~Static179d730() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
