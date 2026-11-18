// Source exposure: binary-analysis; no external implementation source reused.
// Static1765d40, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765d40;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765d40*);
    virtual void release(Static1765d40*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765d40*);
struct Static1765d40 {
    void* value;
    Static1765d40();
    ~Static1765d40() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
