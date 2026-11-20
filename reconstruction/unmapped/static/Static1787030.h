// Source exposure: binary-analysis; no external implementation source reused.
// Static1787030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787030*);
    virtual void release(Static1787030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787030*);
struct Static1787030 {
    void* value;
    Static1787030();
    ~Static1787030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
