// Source exposure: binary-analysis; no external implementation source reused.
// Static1787170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787170*);
    virtual void release(Static1787170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787170*);
struct Static1787170 {
    void* value;
    Static1787170();
    ~Static1787170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
