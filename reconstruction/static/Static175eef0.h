// Source exposure: binary-analysis; no external implementation source reused.
// Static175eef0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175eef0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175eef0*);
    virtual void release(Static175eef0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175eef0*);
struct Static175eef0 {
    void* value;
    Static175eef0();
    ~Static175eef0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
