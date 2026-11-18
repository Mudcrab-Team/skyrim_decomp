// Source exposure: binary-analysis; no external implementation source reused.
// Static179d360, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d360;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d360*);
    virtual void release(Static179d360*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d360*);
struct Static179d360 {
    void* value;
    Static179d360();
    ~Static179d360() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
