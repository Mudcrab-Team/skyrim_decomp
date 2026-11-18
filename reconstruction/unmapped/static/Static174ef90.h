// Source exposure: binary-analysis; no external implementation source reused.
// Static174ef90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174ef90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174ef90*);
    virtual void release(Static174ef90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174ef90*);
struct Static174ef90 {
    void* value;
    Static174ef90();
    ~Static174ef90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
