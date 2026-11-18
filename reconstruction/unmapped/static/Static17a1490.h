// Source exposure: binary-analysis; no external implementation source reused.
// Static17a1490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17a1490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17a1490*);
    virtual void release(Static17a1490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17a1490*);
struct Static17a1490 {
    void* value;
    Static17a1490();
    ~Static17a1490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
