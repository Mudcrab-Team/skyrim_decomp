// Source exposure: binary-analysis; no external implementation source reused.
// Static1761150, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1761150;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1761150*);
    virtual void release(Static1761150*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1761150*);
struct Static1761150 {
    void* value;
    Static1761150();
    ~Static1761150() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
