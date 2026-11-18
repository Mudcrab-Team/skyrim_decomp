// Source exposure: binary-analysis; no external implementation source reused.
// Static1770c90, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770c90;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770c90*);
    virtual void release(Static1770c90*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770c90*);
struct Static1770c90 {
    void* value;
    Static1770c90();
    ~Static1770c90() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
