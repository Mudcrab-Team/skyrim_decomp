// Source exposure: binary-analysis; no external implementation source reused.
// Static1751750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751750*);
    virtual void release(Static1751750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751750*);
struct Static1751750 {
    void* value;
    Static1751750();
    ~Static1751750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
