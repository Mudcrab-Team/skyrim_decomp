// Source exposure: binary-analysis; no external implementation source reused.
// Static1743f20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1743f20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1743f20*);
    virtual void release(Static1743f20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1743f20*);
struct Static1743f20 {
    void* value;
    Static1743f20();
    ~Static1743f20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
