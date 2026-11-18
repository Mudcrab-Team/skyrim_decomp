// Source exposure: binary-analysis; no external implementation source reused.
// Static177c400, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c400;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c400*);
    virtual void release(Static177c400*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c400*);
struct Static177c400 {
    void* value;
    Static177c400();
    ~Static177c400() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
