// Source exposure: binary-analysis; no external implementation source reused.
// Static179e950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e950*);
    virtual void release(Static179e950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e950*);
struct Static179e950 {
    void* value;
    Static179e950();
    ~Static179e950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
