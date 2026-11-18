// Source exposure: binary-analysis; no external implementation source reused.
// Static17b2f80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b2f80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b2f80*);
    virtual void release(Static17b2f80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b2f80*);
struct Static17b2f80 {
    void* value;
    Static17b2f80();
    ~Static17b2f80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
