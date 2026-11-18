// Source exposure: binary-analysis; no external implementation source reused.
// Static17b1490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b1490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b1490*);
    virtual void release(Static17b1490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b1490*);
struct Static17b1490 {
    void* value;
    Static17b1490();
    ~Static17b1490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
