// Source exposure: binary-analysis; no external implementation source reused.
// Static175ea40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ea40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ea40*);
    virtual void release(Static175ea40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ea40*);
struct Static175ea40 {
    void* value;
    Static175ea40();
    ~Static175ea40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
