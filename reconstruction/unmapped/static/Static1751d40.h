// Source exposure: binary-analysis; no external implementation source reused.
// Static1751d40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1751d40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1751d40*);
    virtual void release(Static1751d40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1751d40*);
struct Static1751d40 {
    void* value;
    Static1751d40();
    ~Static1751d40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
