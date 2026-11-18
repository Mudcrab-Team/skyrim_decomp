// Source exposure: binary-analysis; no external implementation source reused.
// Static177d990, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d990;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d990*);
    virtual void release(Static177d990*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d990*);
struct Static177d990 {
    void* value;
    Static177d990();
    ~Static177d990() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
