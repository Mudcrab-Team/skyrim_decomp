// Source exposure: binary-analysis; no external implementation source reused.
// Static179d690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179d690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179d690*);
    virtual void release(Static179d690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179d690*);
struct Static179d690 {
    void* value;
    Static179d690();
    ~Static179d690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
