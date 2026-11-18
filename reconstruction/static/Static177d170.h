// Source exposure: binary-analysis; no external implementation source reused.
// Static177d170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d170*);
    virtual void release(Static177d170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d170*);
struct Static177d170 {
    void* value;
    Static177d170();
    ~Static177d170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
