// Source exposure: binary-analysis; no external implementation source reused.
// Static1742b60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742b60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742b60*);
    virtual void release(Static1742b60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742b60*);
struct Static1742b60 {
    void* value;
    Static1742b60();
    ~Static1742b60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
