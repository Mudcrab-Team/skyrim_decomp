// Source exposure: binary-analysis; no external implementation source reused.
// Static177d030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d030*);
    virtual void release(Static177d030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d030*);
struct Static177d030 {
    void* value;
    Static177d030();
    ~Static177d030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
