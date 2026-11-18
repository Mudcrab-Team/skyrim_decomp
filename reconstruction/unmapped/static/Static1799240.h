// Source exposure: binary-analysis; no external implementation source reused.
// Static1799240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799240*);
    virtual void release(Static1799240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799240*);
struct Static1799240 {
    void* value;
    Static1799240();
    ~Static1799240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
