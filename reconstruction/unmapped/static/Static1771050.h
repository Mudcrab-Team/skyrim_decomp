// Source exposure: binary-analysis; no external implementation source reused.
// Static1771050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1771050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1771050*);
    virtual void release(Static1771050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1771050*);
struct Static1771050 {
    void* value;
    Static1771050();
    ~Static1771050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
