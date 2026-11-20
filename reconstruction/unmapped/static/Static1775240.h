// Source exposure: binary-analysis; no external implementation source reused.
// Static1775240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1775240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1775240*);
    virtual void release(Static1775240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1775240*);
struct Static1775240 {
    void* value;
    Static1775240();
    ~Static1775240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
