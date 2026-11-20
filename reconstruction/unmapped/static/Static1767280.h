// Source exposure: binary-analysis; no external implementation source reused.
// Static1767280, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767280;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767280*);
    virtual void release(Static1767280*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767280*);
struct Static1767280 {
    void* value;
    Static1767280();
    ~Static1767280() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
