// Source exposure: binary-analysis; no external implementation source reused.
// Static1762550, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1762550;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1762550*);
    virtual void release(Static1762550*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1762550*);
struct Static1762550 {
    void* value;
    Static1762550();
    ~Static1762550() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
