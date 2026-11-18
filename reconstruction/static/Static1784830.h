// Source exposure: binary-analysis; no external implementation source reused.
// Static1784830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784830*);
    virtual void release(Static1784830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784830*);
struct Static1784830 {
    void* value;
    Static1784830();
    ~Static1784830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
