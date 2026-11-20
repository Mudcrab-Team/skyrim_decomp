// Source exposure: binary-analysis; no external implementation source reused.
// Static1778030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1778030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1778030*);
    virtual void release(Static1778030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1778030*);
struct Static1778030 {
    void* value;
    Static1778030();
    ~Static1778030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
