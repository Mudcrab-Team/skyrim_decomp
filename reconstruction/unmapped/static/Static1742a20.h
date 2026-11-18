// Source exposure: binary-analysis; no external implementation source reused.
// Static1742a20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742a20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742a20*);
    virtual void release(Static1742a20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742a20*);
struct Static1742a20 {
    void* value;
    Static1742a20();
    ~Static1742a20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
