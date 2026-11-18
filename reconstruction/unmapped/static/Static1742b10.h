// Source exposure: binary-analysis; no external implementation source reused.
// Static1742b10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1742b10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1742b10*);
    virtual void release(Static1742b10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1742b10*);
struct Static1742b10 {
    void* value;
    Static1742b10();
    ~Static1742b10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
