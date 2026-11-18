// Source exposure: binary-analysis; no external implementation source reused.
// Static177b640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177b640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177b640*);
    virtual void release(Static177b640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177b640*);
struct Static177b640 {
    void* value;
    Static177b640();
    ~Static177b640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
