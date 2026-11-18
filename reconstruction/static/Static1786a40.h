// Source exposure: binary-analysis; no external implementation source reused.
// Static1786a40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1786a40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1786a40*);
    virtual void release(Static1786a40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1786a40*);
struct Static1786a40 {
    void* value;
    Static1786a40();
    ~Static1786a40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
