// Source exposure: binary-analysis; no external implementation source reused.
// Static179e610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e610*);
    virtual void release(Static179e610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e610*);
struct Static179e610 {
    void* value;
    Static179e610();
    ~Static179e610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
