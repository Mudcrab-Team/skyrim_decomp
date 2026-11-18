// Source exposure: binary-analysis; no external implementation source reused.
// Static1782210, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782210;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782210*);
    virtual void release(Static1782210*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782210*);
struct Static1782210 {
    void* value;
    Static1782210();
    ~Static1782210() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
