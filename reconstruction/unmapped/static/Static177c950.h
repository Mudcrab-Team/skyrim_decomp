// Source exposure: binary-analysis; no external implementation source reused.
// Static177c950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c950*);
    virtual void release(Static177c950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c950*);
struct Static177c950 {
    void* value;
    Static177c950();
    ~Static177c950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
