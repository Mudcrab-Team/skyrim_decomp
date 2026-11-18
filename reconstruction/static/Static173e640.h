// Source exposure: binary-analysis; no external implementation source reused.
// Static173e640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173e640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173e640*);
    virtual void release(Static173e640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173e640*);
struct Static173e640 {
    void* value;
    Static173e640();
    ~Static173e640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
