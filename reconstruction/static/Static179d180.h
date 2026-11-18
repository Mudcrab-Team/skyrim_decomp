// Source exposure: binary-analysis; no external implementation source reused.
// Static179d180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d180*);
    virtual void release(Static179d180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d180*);
struct Static179d180 {
    void* value;
    Static179d180();
    ~Static179d180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
