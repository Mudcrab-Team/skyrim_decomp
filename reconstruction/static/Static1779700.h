// Source exposure: binary-analysis; no external implementation source reused.
// Static1779700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1779700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1779700*);
    virtual void release(Static1779700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1779700*);
struct Static1779700 {
    void* value;
    Static1779700();
    ~Static1779700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
