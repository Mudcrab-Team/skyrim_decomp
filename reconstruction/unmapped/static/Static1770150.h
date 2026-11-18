// Source exposure: binary-analysis; no external implementation source reused.
// Static1770150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770150*);
    virtual void release(Static1770150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770150*);
struct Static1770150 {
    void* value;
    Static1770150();
    ~Static1770150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
