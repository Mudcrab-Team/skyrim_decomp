// Source exposure: binary-analysis; no external implementation source reused.
// Static1765750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765750*);
    virtual void release(Static1765750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765750*);
struct Static1765750 {
    void* value;
    Static1765750();
    ~Static1765750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
