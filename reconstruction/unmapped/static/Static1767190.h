// Source exposure: binary-analysis; no external implementation source reused.
// Static1767190, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767190;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767190*);
    virtual void release(Static1767190*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767190*);
struct Static1767190 {
    void* value;
    Static1767190();
    ~Static1767190() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
