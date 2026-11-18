// Source exposure: binary-analysis; no external implementation source reused.
// Static177d260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d260*);
    virtual void release(Static177d260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d260*);
struct Static177d260 {
    void* value;
    Static177d260();
    ~Static177d260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
