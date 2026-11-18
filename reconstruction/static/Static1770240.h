// Source exposure: binary-analysis; no external implementation source reused.
// Static1770240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1770240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1770240*);
    virtual void release(Static1770240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1770240*);
struct Static1770240 {
    void* value;
    Static1770240();
    ~Static1770240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
