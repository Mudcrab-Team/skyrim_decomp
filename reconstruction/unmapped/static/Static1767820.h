// Source exposure: binary-analysis; no external implementation source reused.
// Static1767820, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767820;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767820*);
    virtual void release(Static1767820*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767820*);
struct Static1767820 {
    void* value;
    Static1767820();
    ~Static1767820() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
