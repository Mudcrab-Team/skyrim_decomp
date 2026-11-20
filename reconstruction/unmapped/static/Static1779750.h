// Source exposure: binary-analysis; no external implementation source reused.
// Static1779750, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779750;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779750*);
    virtual void release(Static1779750*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779750*);
struct Static1779750 {
    void* value;
    Static1779750();
    ~Static1779750() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
