// Source exposure: binary-analysis; no external implementation source reused.
// Static1764170, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764170;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764170*);
    virtual void release(Static1764170*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764170*);
struct Static1764170 {
    void* value;
    Static1764170();
    ~Static1764170() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
