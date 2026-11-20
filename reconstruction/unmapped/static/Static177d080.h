// Source exposure: binary-analysis; no external implementation source reused.
// Static177d080, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d080;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d080*);
    virtual void release(Static177d080*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d080*);
struct Static177d080 {
    void* value;
    Static177d080();
    ~Static177d080() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
