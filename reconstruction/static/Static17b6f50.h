// Source exposure: binary-analysis; no external implementation source reused.
// Static17b6f50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17b6f50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17b6f50*);
    virtual void release(Static17b6f50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17b6f50*);
struct Static17b6f50 {
    void* value;
    Static17b6f50();
    ~Static17b6f50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
