// Source exposure: binary-analysis; no external implementation source reused.
// Static1765250, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1765250;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1765250*);
    virtual void release(Static1765250*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1765250*);
struct Static1765250 {
    void* value;
    Static1765250();
    ~Static1765250() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
