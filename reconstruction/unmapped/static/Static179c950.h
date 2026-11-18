// Source exposure: binary-analysis; no external implementation source reused.
// Static179c950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179c950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179c950*);
    virtual void release(Static179c950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179c950*);
struct Static179c950 {
    void* value;
    Static179c950();
    ~Static179c950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
