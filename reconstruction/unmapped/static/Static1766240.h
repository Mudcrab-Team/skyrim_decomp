// Source exposure: binary-analysis; no external implementation source reused.
// Static1766240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1766240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1766240*);
    virtual void release(Static1766240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1766240*);
struct Static1766240 {
    void* value;
    Static1766240();
    ~Static1766240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
